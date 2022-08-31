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

int a[100000];
vi one,two,three;
int nn[100000],col[100000];
vpii ans;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    fill(nn,nn+n,-1);
    for (i = n-1; i >= 0; i--) {
        if (a[i] == 1) one.pb(i);
        else if (a[i] == 2) {
            if (one.empty()) {
                printf("-1\n");
                return 0;
            }
            nn[i] = one.back();
            one.pop_back();
            two.pb(i);
        }
        else if (a[i] == 3) {
            if (!three.empty()) {
                nn[i] = three.back();
                three.pop_back();
            }
            else if (!two.empty()) {
                nn[i] = two.back();
                two.pop_back();
            }
            else {
                if (one.empty()) {
                    printf("-1\n");
                    return 0;
                }
                nn[i] = one.back();
                one.pop_back();
            }
            three.pb(i);
        }
    }
    int c = n-1;
    for (i = n-1; i >= 0; i--) {
        if (a[i] == 1) ans.pb(mp(i,c)),col[i] = c,c--;
        else if (a[i] == 2) ans.pb(mp(i,col[nn[i]])),col[i] = col[nn[i]];
        else if (a[i] == 3) ans.pb(mp(i,c)),ans.pb(mp(nn[i],c)),col[i] = col[nn[i]],c--;
    }
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].second+1,ans[i].first+1);

    return 0;
}