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

LLI area[1000];
plli p[1000];
vi hull1,hull2,ans;
int cross(int a,int b,int c) {
    int s;
    cout << "2 " << a+1 << " " << b+1 << " " << c+1 << endl;
    cin >> s;
    return s;
}
int main() {
    int i;
    int n;
    cin >> n;

    area[0] = area[1] = 0;
    for (i = 2; i < n; i++) {
        int s;
        cout << "1 1 2 " << i+1 << endl;
        cin >> area[i];
        cout << "2 1 2 " << i+1 << endl;
        cin >> s;
        area[i] *= s;
    }
    for (i = 0; i < n; i++) p[i] = mp(area[i],i);
    sort(p,p+n);
    for (i = 0; i < n; i++) {
        if ((hull1.size() >= 2) && (cross(hull1[hull1.size()-2],hull1.back(),p[i].second) == -1)) {
            hull2.pb(hull1.back());
            hull1.pop_back();
        }
        hull1.pb(p[i].second);
    }
    ans = hull1;
    for (i = (int) hull2.size()-1; i >= 0; i--) ans.pb(hull2[i]);
    for (i = 0; i < n; i++) {
        if (ans[i] == 0) break;
    }
    int x = i;
    cout << "0";
    for (i = 0; i < n; i++) cout << " " << ans[(i+x) % n]+1;
    cout << endl;

    return 0;
}