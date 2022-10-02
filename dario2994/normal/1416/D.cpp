#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// 20:41

const int MAXN = 1<<18;

int val[2*MAXN];
int who[2*MAXN];
pair<int,int> query(int v, int l, int r, int a, int b) {
    if (a <= l and r <= b) return {val[v], who[v]};
    if (r < a or b < l) return {-1, -1};
    int m = (l+r)/2;
    auto ppl = query(2*v, l, m, a, b);
    auto ppr = query(2*v+1, m+1, r, a, b);
    if (ppl.first >= ppr.first) return ppl;
    return ppr;
}

void update(int v) {
    if (val[2*v] >= val[2*v+1]) {
        val[v] = val[2*v];
        who[v] = who[2*v];
    } else {
        val[v] = val[2*v+1];
        who[v] = who[2*v+1];
    }
}

void reset_val(int v) {
    v += MAXN;
    val[v] = 0;
    who[v] = v-MAXN;
    while (v > 1) {
        v /= 2;
        update(v);
    }
}


int anc[MAXN];
int ll[MAXN];
int rr[MAXN];

int bef[MAXN], aft[MAXN];

int ancestor(int v) {
    if (anc[anc[v]] != anc[v]) anc[v] = ancestor(anc[v]);
    return anc[v];
}

int join(int u, int v) {
    u = ancestor(u);
    v = ancestor(v);
    if (u == v) return 0;
    aft[rr[u]] = ll[v];
    bef[ll[v]] = rr[u];
    rr[u] = rr[v];
    anc[v] = u;
    return bef[ll[v]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> pinfo(N+1);
    for (int v = 1; v <= N; v++) cin >> pinfo[v];
    vector<int> from(M+1), to(M+1);
    vector<bool> removed(M+1, false);
    for (int e = 1; e <= M; e++) cin >> from[e] >> to[e];

    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) queries[i] = b;
        else {
            removed[b] = true;
            queries[i] = -b;
        }
    }
    for (int e = 1; e <= M; e++) {
        if (!removed[e]) queries.push_back(-e);
    }
    
    for (int v = 1; v <= N; v++) anc[v] = v, ll[v] = v, rr[v] = v;
    
    reverse(queries.begin(), queries.end());
    for (int& e: queries) {
        if (e > 0) continue;
        e = -e;
        e = -join(from[e], to[e]);
    }
    reverse(queries.begin(), queries.end());

    set<pair<int,int>> inter;
    vector<int> pos(N+1);
    vector<int> ord;
    for (int v = 1; v <= N; v++) {
        if (bef[v]) continue;
        int z = v;
        int w = -1;
        while (z) {
            w = z;
            pos[z] = ord.size();
            ord.push_back(z);
            z = aft[z];
        }
        inter.insert({pos[v], pos[w]});
    }
    assert(SZ(ord) == N);

    for (int v = 0; v < MAXN; v++) {
        who[v + MAXN] = v;
        if (v < N) val[v + MAXN] = pinfo[ord[v]];
    }
    for (int v = MAXN-1; v >= 1; v--) update(v);

    // cout << query(1, 0, MAXN-1, 0, N-1) << "\n";
    // return 0;

    for (int z: queries) {
        if (z < 0) {
            int p = pos[-z];
            auto it = inter.lower_bound({p+1, -1});
            assert(it != inter.begin());
            it--;
            int a = it->first, b = it->second;
            assert(a <= p and p < b);
            inter.erase(it);
            inter.insert({a, p});
            inter.insert({p+1, b});
        } else if (z > 0) {
            int p = pos[z];
            auto it = inter.lower_bound({p+1, -1});
            assert(it != inter.begin());
            it--;
            int a = it->first, b = it->second;
            assert(a <= p and p <= b);

            auto ans = query(1, 0, MAXN-1, a, b);
            cout << ans.first << "\n";
            reset_val(ans.second);
            // int ans = 0;
            // for (int i = a; i <= b; i++) ans = max(ans, pinfo[ord[i]]);
            // for (int i = a; i <= b; i++) if (pinfo[ord[i]] == ans) {
                // pinfo[ord[i]] = 0;
                // break;
            // }
            // cout << ans << "\n";
        }
    }
}