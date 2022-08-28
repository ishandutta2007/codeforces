#define DEBUG 1

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------
#define MOD 1000000007
#define X 10000000
#define Y 1000000

bitset<X+1> bs;
int f[X+1][8],len[X+1];
vi primes;
int in[X+1];
vi adjList[100000];
int parent[100000][17],depth[100000];
int disc[100000],fin[100000],num = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p;
    disc[u] = num++,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    fin[u] = num;
    return 0;
}
int lca(int u,int v,int logn) {
    int i;
    if (depth[u] < depth[v]) swap(u,v);
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
struct query { int u,v,l,x,i; };
bool comp(query a,query b) {
    return a.x < b.x;
}
vector<query> Q[Y];
vpii U[Y];
LLI ans[100000];
int bit[100001],bit2[100001];
int main() {
    int i,j;
    bs.set();
    bs[0] = bs[1] = 0;
    for (i = 2; i <= X; i++) {
        if (bs[i]) {
            for (j = i; j <= X; j += i) bs[j] = 0,f[j][len[j]++] = i;
            in[i] = primes.size();
            primes.pb(i);
        }
    }

    int n,q,u,v,x;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    int logn = i;
    for (i = 0; i < n; i++) {
        scanf("%d",&x);
        for (j = 0; j < len[x]; j++) U[in[f[x][j]]].pb(mp(x,i));
    }
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&u,&v,&x);
        u--,v--;
        for (j = 0; j < len[x]; j++) Q[in[f[x][j]]].pb((query){u,v,lca(u,v,logn),x,i});
        ans[i] = 1;
    }

    int k,l;
    for (i = 0; i < primes.size(); i++) {
        vpii U2;
        vector<query> Q2;
        for (j = 0; j < U[i].size(); j++) {
            x = U[i][j].first;
            int c = 0;
            while ((x % primes[i]) == 0) x /= primes[i],c++;
            U2.pb(mp(c,U[i][j].second));
            for (k = disc[U[i][j].second]+1; k <= n; k += k & (-k)) bit2[k]++;
            for (k = fin[U[i][j].second]+1; k <= n; k += k & (-k)) bit2[k]--;
        }
        for (j = 0; j < Q[i].size(); j++) {
            x = Q[i][j].x;
            int c = 0;
            while ((x % primes[i]) == 0) x /= primes[i],c++;
            Q2.pb((query){Q[i][j].u,Q[i][j].v,Q[i][j].l,c,Q[i][j].i});
        }
        sort(U2.begin(),U2.end());
        sort(Q2.begin(),Q2.end(),comp);
        k = 0;
        for (j = 0; j < Q2.size(); j++) {
            while ((k < U2.size()) && (U2[k].first < Q2[j].x)) {
                for (l = disc[U2[k].second]+1; l <= n; l += l & (-l)) {
                    bit[l] += U2[k].first;
                    bit2[l]--;
                }
                for (l = fin[U2[k].second]+1; l <= n; l += l & (-l)) {
                    bit[l] -= U2[k].first;
                    bit2[l]++;
                }
                k++;
            }
            int c = 0;
            for (l = disc[Q2[j].u]+1; l > 0; l -= l & (-l)) c += bit[l]+Q2[j].x*bit2[l];
            for (l = disc[Q2[j].l]+1; l > 0; l -= l & (-l)) c -= bit[l]+Q2[j].x*bit2[l];
            for (l = disc[Q2[j].v]+1; l > 0; l -= l & (-l)) c += bit[l]+Q2[j].x*bit2[l];
            if (parent[Q2[j].l][0] != -1) {
                for (l = disc[parent[Q2[j].l][0]]+1; l > 0; l -= l & (-l)) c -= bit[l]+Q2[j].x*bit2[l];
            }
            LLI b = primes[i];
            while (c > 0) {
                if (c & 1) ans[Q2[j].i] *= b,ans[Q2[j].i] %= MOD;
                c >>= 1;
                b *= b,b %= MOD;
            }
        }
        for (j = 0; j < U2.size(); j++) {
            for (k = disc[U2[j].second]+1; k <= n; k += k & (-k)) bit[k] = bit2[k] = 0;
            for (k = fin[U2[j].second]+1; k <= n; k += k & (-k)) bit[k] = bit2[k] = 0;
        }
    }
    for (i = 0; i < q; i++) printf("%I64d\n",ans[i]);

    return 0;
}