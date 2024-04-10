#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int n, paths;
ull a, b, c;

#define MAXN 200005

vector<int> Paths[MAXN];
vector<pair<int, int>> G[MAXN];
int Heavy[MAXN], In[MAXN], PathP[MAXN], ParentE[MAXN], Which[MAXN], D[MAXN], Pos[MAXN];

ull Cost[MAXN];

void dfs(int node) {
    Heavy[node] = 1;

    int best = 0, choose = -1;

    for(auto e : G[node]) {
        int vec = e.first;
        if(!Heavy[vec]) {
            D[vec] = D[node] + 1;
            ParentE[vec] = e.second;
            Which[e.second] = vec;

            dfs(vec);

            Heavy[node] += Heavy[vec];
            PathP[In[vec]] = node;

            if(best < Heavy[vec]) {
                best = Heavy[vec];
                choose = In[vec];
            }
        }
    }

    if(choose == -1) choose = ++paths;
    In[node] = choose;

    Paths[In[node]].push_back(node);
}

const ull MAXX = 2e18;

ull inm(ull a, ull b) {
    if(a == 0 || b == 0) return 0;
    ull r = a * b;
    if(r / a == b) return r;
    return MAXX;
}

struct ArbInt {
    vector<ull> T;
    int n;

    void _init(int node, int b, int e, int i) {
        if(b == e) {
            int where = Paths[i][b];
            T[node] = Cost[ParentE[where]];
        } else {

            int m = b + e >> 1;
            _init(node*2, b, m, i);
            _init(node*2+1, m+1, e, i);

            T[node] = inm(T[node*2], T[node*2+1]);
        }
    }

    void init(int sz, int i) {
        T.resize(sz*4);
        n = sz;

        _init(1, 1, n, i);
    }

    void _upd(int node, int b, int e, int pos, ull val) {
        if(b == e) {
            T[node] = val;
        } else {
            int m = b + e >> 1;
            if(m >= pos) _upd(node*2, b, m, pos, val);
            else _upd(node*2+1, m+1, e, pos, val);

            T[node] = inm(T[node*2], T[node*2+1]);
        }
    }

    void update(int pos, ull val) {
        _upd(1, 1, n, pos, val);
    }

    ull _qry(int node, int b, int e, int l, int r) {
        if(b > r || e < l) return 1LL;
        if(b >= l && e <= r) return T[node];

        int m = b + e >> 1;
        return inm(_qry(node*2, b, m, l, r), _qry(node*2+1, m+1, e, l, r));
    }


    ull query(int l, int r) {
        return _qry(1, 1, n, l, r);
    }
};
ArbInt AI[MAXN];

void update(int node, ull val) {
    int where = In[node];
    AI[where].update(Pos[node], val);
}

ull query(int a, int b, ull x) {
    while(In[a] != In[b]) {
        if(D[PathP[In[a]]] > D[PathP[In[b]]]) {
            x /= AI[In[a]].query(1, Pos[a]);
            a = PathP[In[a]];
        } else {
            x /= AI[In[b]].query(1, Pos[b]);
            b = PathP[In[b]];
        }

        if(x == 0LL) return 0LL;
    }

    if(a != b) {
        if(Pos[a] > Pos[b]) swap(a, b);
        x /= AI[In[a]].query(Pos[a] + 1, Pos[b]);
    }

    return x;
}

ull Read() {
    char c; ull a = 0;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(; isdigit(c); c = getchar())
        a = (a << 1LL) + (a << 3LL) + c - '0';
    return a;
}

void w(ull a) {
    if(a != 0) {
        w(a / 10);
        putchar(a % 10 + '0');
    }
}

void Write(ull a) {
    if(a == 0) {
        putchar('0');
    } else {
        w(a);
    }
    putchar('\n');
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, m;
    n = Read(); m = Read();

    for(int i=1; i<n; i++) {
        a = Read(); b = Read(); c = Read();
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        Cost[i] = c;
    }

    D[0] = -1;

    srand(time(0));

    int root = rand() % n + 1;
    dfs(root);
    PathP[In[root]] = 0;
    Cost[0] = 1;

    for(int i=1; i<=paths; i++) {
        auto &curp = Paths[i];

        curp.push_back(0);
        reverse(curp.begin(), curp.end());

        //cout<<PathP[i]<<": ";
        for(int i=1; i<curp.size(); i++) {
            Pos[curp[i]] = i;
            //cout<<curp[i]<<" ";
        }
        AI[i].init(curp.size()-1, i);
        //cout<<endl;
    }


    ull t;
    while(m--) {
        t = Read(); a = Read(); b = Read();
        if(t == 1) {
            c = Read();
            Write(query(a, b, c));
        } else {
            update(Which[a], b);
        }
    }


    return 0;
}