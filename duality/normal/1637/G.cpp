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

vpii sol;
vi solve(int n,int m) {
    if (n == 0) return {};
    else if (n == 1) return {m};
    else if (n == 2) return {m,2*m};

    int p = n;
    while (p != (1 << __lg(p))) p++;
    if (p == n) {
        vi v = solve(n-1,m);
        v.pb(n*m);
        return v;
    }
    vi v = solve(p-n-1,m);
    int l = p-n,r = n;
    while (l < r) {
        sol.pb(mp(l*m,r*m));
        v.pb((l+r)*m),l++,r--;
    }
    vi v2 = solve(n-p/2,2*m);
    v.pb(l*m),v.insert(v.end(),v2.begin(),v2.end());
    return v;
}
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        if (n == 2) printf("-1\n");
        else {
            vi v = solve(n,1);
            sort(v.begin(),v.end());
            for (i = 1; i < v.size(); i++) {
                if ((v[i-1] == v[i]) && (v[i] != v.back())) {
                    sol.pb(mp(v[i],v[i]));
                    v[i] *= 2,v.erase(v.begin()+i-1);
                    break;
                }
            }
            for (int x: v) {
                while (x != v.back()) {
                    sol.pb(mp(x,0));
                    sol.pb(mp(x,x));
                    x *= 2;
                }
            }
            sol.pb(mp(v.back(),0));
            printf("%d\n",sol.size());
            for (auto [x,y]: sol) printf("%d %d\n",x,y);
            sol.clear();
        }
    }

    return 0;
}