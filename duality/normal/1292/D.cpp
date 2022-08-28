#define DEBUG 0

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

int occ[5001];
vi primes;
int c[5000];
struct edge { int u,v,l; };
class comp {
    public:
        bool operator()(edge a,edge b) const {
            if (min(a.u,a.v) == min(b.u,b.v)) return max(a.u,a.v) < max(b.u,b.v);
            else return min(a.u,a.v) < min(b.u,b.v);
        }
};
set<edge,comp> S;
int node[5001],num = 0;
vpii adjList[1000000];
int w[1000000];
LLI dist[1000000],sub[1000000];
int doDFS(int u,int p,LLI d) {
    int i;
    dist[0] += d*w[u],sub[u] = w[u];
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) {
            doDFS(v,u,d+adjList[u][i].second);
            sub[u] += sub[v];
        }
    }
    return 0;
}
LLI ans;
int doDFS2(int u,int p) {
    int i;
    ans = min(ans,dist[u]);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) {
            dist[v] = dist[u]+(LLI) adjList[u][i].second*(sub[0]-2*sub[v]);
            doDFS2(v,u);
        }
    }
    return 0;
}
int main() {
    int i;
    int n,k;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&k),occ[k]++;
    //for(i=1;i<=5;i++)cout<<occ[i]<<" ";
    //cout<<endl;

    int j;
    for (i = 2; i <= 5000; i++) {
        int f = 0;
        for (j = 2; j*j <= i; j++) {
            if ((i % j) == 0) {
                f = 1;
                break;
            }
        }
        if (!f) primes.pb(i);
    }
    //for(i=0;i<primes.size();i++)cout<<primes[i]<<endl;
    vpii path;
    path.pb(mp(0,0));
    node[1] = 0,num = 1;
    for (i = 2; i <= 5000; i++) {
        int t = i,m = 0,mm = 0;
        for (j = 0; j < primes.size(); j++) {
            if ((t % primes[j]) == 0) {
                mm = 0;
                while ((t % primes[j]) == 0) c[j]++,mm++,t /= primes[j];
                m = j;
            }
        }
        int l = 0;
        for (j = 0; j < m; j++) l += c[j];
        l += mm;
        int all = 0,all2 = 0;
        for (j = 0; j < primes.size(); j++) all += c[j];
        for (j = 0; j < path.size(); j++) all2 += path[j].second;
        printVar(i);
        printVar(all);
        printVar(all2);
        printVar(l);
        node[i] = num++;
        int d = 0;
        while (all2 > all-l) {
            if (all2-path.back().second >= all-l) all2 -= path.back().second,path.pop_back();
            else {
                pii p = path.back();
                path.pop_back();
                assert(S.find((edge){p.first,path.back().first,p.second}) != S.end());
                S.erase((edge){p.first,path.back().first,p.second});
                S.insert((edge){p.first,num,all2-(all-l)});
                S.insert((edge){num,path.back().first,p.second-(all2-(all-l))});
                path.pb(mp(num,p.second-(all2-(all-l))));
                num++;
                d = 1;
                break;
            }
        }
        S.insert((edge){node[i],path.back().first,l});
        path.pb(mp(node[i],l));
        //for(j=0;j<path.size();j++)cout<<path[j].first<<","<<path[j].second<<" ";
        //cout<<endl;
        /*cout<<all<<endl;
        for (auto it = S.begin(); it != S.end(); it++) {
        cout << it->u<<","<<it->v<<","<<it->l<<endl;
    }*/

    }
    for (auto it = S.begin(); it != S.end(); it++) {
        adjList[it->u].pb(mp(it->v,it->l));
        adjList[it->v].pb(mp(it->u,it->l));
    }
    for (i = 1; i <= 5000; i++) w[node[i]] = occ[i];
    w[0] += occ[0]; // GOD DAMMIT
    doDFS(0,-1,0);
    ans = dist[0];
    doDFS2(0,-1);
    printf("%I64d\n",ans);

/*
    for (auto it = S.begin(); it != S.end(); it++) {
        cout << it->u<<","<<it->v<<","<<it->l<<endl;
    }*/


    return 0;
}