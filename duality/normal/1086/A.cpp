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

pii p[3];
vpii ans;
int main() {
    int i,j;
    for (i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
    sort(p,p+3);

    int bi,bj,m = 1e9;
    for (i = 0; i <= 1000; i++) {
        for (j = 0; j <= 1000; j++) {
            int d1 = abs(p[0].first-i)+abs(p[0].second-j);
            int d2 = abs(p[1].first-i)+abs(p[1].second-j);
            int d3 = abs(p[2].first-i)+abs(p[2].second-j);
            if (d1+d2+d3+1 < m) m = d1+d2+d3+1,bi = i,bj = j;
        }
    }
    for (i = 0; i < 3; i++) {
        pii c = p[i],d = mp(bi,bj);
        if (c > d) swap(c,d);
        for (j = c.first; j < d.first; j++) ans.pb(mp(j,c.second));
        if (c.second <= d.second) {
            for (j = c.second; j <= d.second; j++) ans.pb(mp(d.first,j));
        }
        else {
            for (j = c.second; j >= d.second; j--) ans.pb(mp(d.first,j));
        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first,ans[i].second);

    return 0;
}