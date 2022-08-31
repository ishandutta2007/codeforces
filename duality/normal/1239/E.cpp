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

int a[50],ans[2][25];
bitset<1250001> bs[25];
vi v;
vpii poss1[25];
multiset<int> S;
int main() {
    int i;
    int n,sum = 0;
    scanf("%d",&n);
    for (i = 0; i < 2*n; i++) scanf("%d",&a[i]),sum += a[i];
    sort(a,a+2*n);

    int j,k;
    int best = 1e9,bi,bj;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < n; j++) bs[j].reset();
        bs[0][0] = 1;
        for (j = 1; j < 2*n; j++) {
            if ((j != i) && (a[j] >= a[i])) {
                for (k = n-1; k > 0; k--) bs[k] |= bs[k-1] << a[j];
            }
        }
        for (j = 0; j <= n*50000; j++) {
            if (bs[n-1][j]) {
                if (max(j+a[0]+a[i],sum-j) < best) best = max(j+a[0]+a[i],sum-j),bi = i,bj = j;
            }
        }
    }
    ans[0][0] = a[0],ans[1][n-1] = a[bi];
    for (i = 1; i < 2*n; i++) {
        if ((i != bi) && (a[i] >= a[bi])) v.pb(a[i]);
    }
    int h = v.size()/2;
    for (i = 0; i < (1 << h); i++) {
        int b = 0,s = 0;
        for (j = 0; j < h; j++) {
            if (i & (1 << j)) b++,s += v[j];
        }
        poss1[b].pb(mp(s,i));
    }
    for (i = 0; i < (1 << (v.size()-h)); i++) {
        int b = 0,s = 0;
        for (j = 0; j < v.size()-h; j++) {
            if (i & (1 << j)) b++,s += v[j+h];
        }
        int p = lower_bound(poss1[n-b-1].begin(),poss1[n-b-1].end(),mp(bj-s,0))-poss1[n-b-1].begin();
        if ((p < poss1[n-b-1].size()) && (poss1[n-b-1][p].first == bj-s)) {
            vi vv;
            for (j = 0; j < h; j++) {
                if (poss1[n-b-1][p].second & (1 << j)) vv.pb(v[j]);
            }
            for (j = 0; j < v.size()-h; j++) {
                if (i & (1 << j)) vv.pb(v[j+h]);
            }
            sort(vv.begin(),vv.end());
            for (j = 0; j < vv.size(); j++) ans[1][n-j-2] = vv[j];
            break;
        }
    }
    for (i = 1; i < 2*n; i++) {
        if (i != bi) S.insert(a[i]);
    }
    for (i = 0; i < n-1; i++) S.erase(S.find(ans[1][i]));
    i = 1;
    for (auto it = S.begin(); it != S.end(); it++) ans[0][i++] = *it;
    for (i = 0; i < n; i++) printf("%d ",ans[0][i]);
    printf("\n");
    for (i = 0; i < n; i++) printf("%d ",ans[1][i]);
    printf("\n");

    return 0;
}