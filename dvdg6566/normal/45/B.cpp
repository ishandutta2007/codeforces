#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

int V[MAXN];
int W[MAXN];
int N,M,a,b,p;
int A[MAXN];
int B[MAXN];
int cur,res;
int vis[MAXN];
int cyc[MAXN];
int pos[MAXN];
pi clen[MAXN];
int nxt[MAXN];
int ln[MAXN];
int exist[MAXN];

void check(int x){
    if (vis[x])return;
    a = b = x;
    do {
        a = V[a];
        if (vis[a])return;
        vis[a] = 1;
        b = V[b];
        b = V[b];
    } while (a != b);
    // cout<<"Cyc "<<a<<'\n';
    pos[a] = ++p;
    vis[a] = 1;
    // cout << "Checked "<<cur<<' '<<a<<'\n';
    do{
        a = V[a];
        b = V[V[b]];
        vis[a] = 1;
        if(a==b)break;
        cyc[a] = cur;
        pos[a] = ++p;
    }while (a != b);
    vis[a] = 1;
    clen[cur] = mp(pos[a], p);
    cyc[a] = cur++;
}

struct node{
    int s,e,m,v;
    node *l, *r;
    node(int _s, int _e): s(_s), e(_e) {
        m=(s+e)/2;v=0;
        if (s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
        }
    }
    void up (int x, int y){
        if (v == e - s + 1){
            // All the descendant nodes are already filled up
            return;
        }
        if (x == s && y == e){
            // cout<<"Filling up "<<s<<' '<<e<<'\n';
            v = e-s+1;
            return;
        }
        if (y <= m)l->up(x,y);
        else if (x > m)r->up(x,y);
        else{
            l->up(x,m);
            r->up(m+1,y);
        }
        v = l->v + r->v;
    }
    int query(int x, int y){ // Count number of zeroes in the range
        if (v == e - s + 1){
            // All filled up, return 0;
            return 0;
        }
        if (s == x && y == e){
            return e-s+1-v; // Size of range minus number of ones
        }
        if (y <= m)return l->query(x,y);
        else if (x > m)return r->query(x,y);
        return l->query(x,m) + r->query(m+1, y);
    }
}*root;

void pp (pi a){cout<<a.f<<' '<<a.s<<'\n';}

int resolve(int a, int b){
    // cout<<"Resolve "<<a<<' '<<b<<'\n';
    pi r = clen[cyc[a]];
    int l = r.s - r.f + 1; // Length of cycle
    // cout<<r.f<<' '<<r.s<<'\n';
    int cp = pos[a];
    if (b > l)b = l;
    pi fst = mp(cp, min(cp+b, r.s));
    // pp(fst);
    b -= (fst.s - fst.f+1);
    int ans = 0;
    ans += root->query(fst.f, fst.s);
    root->up(fst.f,fst.s);
    if (b >= 0){
        fst = mp(r.f, r.f + b);
        // pp(fst);
        ans += root->query(fst.f, fst.s);
        root->up(fst.f,fst.s);
    }
    return ans;
}

pi par(int x){
    if (x == nxt[x])return mp(x,0);
    pi t = par(nxt[x]);
    nxt[x] = t.f;
    ln[x] += t.s;
    return mp(nxt[x], ln[x]);
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("o2.txt","w",stdout);
    cin >> N >> M;
    for (int i=1;i<=N;++i){
        cin>>V[i];
        W[i]=1;
        exist[i]=1;
    }
    root = new node(1,N);
    for (int i=1;i<=M;++i)cin>>A[i];
    for (int i=1;i<=M;++i)cin>>B[i];
    cur = 1;
    for (int i=1;i<=N;++i){
        check(i);
    }

    for (int i=1;i<=N;++i){
        nxt[i] = i;
        ln[i] = 0;
    }

    // for (int i=1;i<=N;++i)if (cyc[i])cout<<i<<' '<<cyc[i]<<' '<<pos[i]<<' '<<V[i]<<'\n';
    // cout<<'\n';

    for (int i=1;i<=M;++i){
        int a = (A[i] + res - 1) % N + 1;
        int b = B[i];
        // cout<<"Running from "<<a<<" for "<<b<<'\n';
        if (cyc[a]){
            // a is part of a cycle
            res = resolve(a, b-1);
            cout << res << '\n';
        }else{
            int ans = 0;
            while (b && !cyc[a]){
                pi t = par(V[a]);
                // cout<<"From "<<a<<" map ";pp(t);
                // pp(t);
                if (exist[a]){
                    // cout<<"Removing "<<a<<'\n';
                    ++ans;
                }
                exist[a] = 0;
                nxt[a] = t.f;
                ln[a] = 1 + t.s;
                if (ln[a] + 1 > b){b = -1; break;}
                b -= ln[a];
                a = nxt[a];
                // cout<<"At "<<a<<" with "<<b<<" left "<<'\n';
            }
            // cout<<a<<' '<<b<<' '<<ans<<'\n';
            if (b > 0)ans += resolve(a, b-1);
            res = ans;
            cout<<ans<<'\n';
        }
    }

    // for (int i=1;i<=N;++i)cout<<nxt[i]<<' '<<ln[i]<<'\n';
}