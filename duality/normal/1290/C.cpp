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

char s[300000];
vi occ[300000];
pii parent[300001];
int size[300001],sizer[300001];
pii find(int n) {
    if (parent[n].first != n) {
        pii p = find(parent[n].first);
        parent[n] = mp(p.first,p.second^parent[n].second);
    }
    return parent[n];
}
int ans[300000],m = 0;
int getCom(int u) {
    u = find(u).first;
    return (u == 0) ? size[u]:min(sizer[u],size[u]);
}
int merge(int a,int b,int t) {
    //cout<<a<<","<<b<<": "<<t<<endl;
    pii p = find(a),q = find(b);
    t ^= p.second^q.second;
    if (p.first == q.first) {
        assert(t == 0);
        return 0;
    }
    //printVar(m);
    m -= getCom(a),m -= getCom(b);
    //printVar(m);
    if (p.first < q.first) swap(p,q);
    parent[p.first] = mp(q.first,t);
    sizer[q.first] += t ? size[p.first]:sizer[p.first];
    size[q.first] += t ? sizer[p.first]:size[p.first];
    m += getCom(a);
    return 0;
}
int main() {
    int i,j;
    int n,k,c,x;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);
    for (i = 0; i < k; i++) {
        scanf("%d",&c);
        for (j = 0; j < c; j++) scanf("%d",&x),occ[x-1].pb(i);
    }

    for (i = 0; i <= k; i++) parent[i] = mp(i,0),sizer[i] = 1;
    for (i = 0; i < n; i++) {
        if (occ[i].size() == 1) {
            if (s[i] == '0') merge(0,occ[i][0]+1,1);
            else merge(0,occ[i][0]+1,0);
        }
        else if (occ[i].size() == 2) {
            if (s[i] == '0') merge(occ[i][0]+1,occ[i][1]+1,1);
            else merge(occ[i][0]+1,occ[i][1]+1,0);
        }
        ans[i] = m;
    }
    for (i = 0; i < n; i++) printf("%d\n",ans[i]);

    return 0;
}