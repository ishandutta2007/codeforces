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

vpii ans;
int findAns(int l,int r) {
    if (l == r) return 0;
    int i,m = (l+r) / 2;
    findAns(l,m),findAns(m+1,r);
    for (i = l; i <= m; i++) ans.pb(mp(i,i+(m-l+1)));
    return 0;
}
bool comp(vi &a,vi &b) {
    return a.size() < b.size();
}
int main() {
    int n;
    cin >> n;

    int i,j,c = 0;
    vector<vi> vv;
    for (i = 0; i < 20; i++) {
        if (n & (1 << i)) {
            findAns(c,c+(1 << i)-1);
            vi v;
            for (j = c; j < c+(1 << i); j++) v.pb(j);
            vv.pb(v);
            c += (1 << i);
        }
    }
    while (vv.size() > 2) {
        sort(vv.begin(),vv.end(),comp);
        if (vv[0].size() == vv[1].size()) {
            for (j = 0; j < vv[0].size(); j++) ans.pb(mp(vv[0][j],vv[1][j])),vv[1].pb(vv[0][j]);
            vv[0].clear();
            swap(vv[0],vv.back());
            vv.pop_back();
        }
        else {
            for (j = 0; j < vv[0].size(); j++) ans.pb(mp(vv[0][j],vv.back()[vv.back().size()-j-1]));
            int s = vv[0].size();
            for (j = 0; j < s; j++) vv[0].pb(vv.back().back()),vv.back().pop_back();
        }
    }
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);

    return 0;
}