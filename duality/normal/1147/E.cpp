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

string query(vpii v) {
    if (v.empty()) return "";
    int i;
    string ans;
    cout << "Q " << v.size();
    for (i = 0; i < v.size(); i++) cout << " " << v[i].first+1 << " " << v[i].second+1;
    cout << endl;
    cin >> ans;
    return ans;
}
char arr[100000];
vi sol[3];
int main() {
    int i,j;
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;

        vpii v;
        string a,b;
        for (i = 0; i < n-1; i += 2) v.pb(mp(i,i+1));
        a = query(v),v.clear();
        for (i = 1; i < n-1; i += 2) v.pb(mp(i,i+1));
        b = query(v),v.clear();
        vi x,ans;
        x.pb(0);
        for (i = 0; i < n-1; i++) {
            if (i & 1) arr[i] = b[i/2];
            else arr[i] = a[i/2];
            if (arr[i] == '0') x.pb(i+1);
        }
        ans.resize(x.size()+2);
        for (i = 0; i < (int) x.size()-2; i += 4) {
            v.pb(mp(x[i],x[i+2]));
            if (i+3 < x.size()) v.pb(mp(x[i+1],x[i+3]));
        }
        a = query(v),v.clear();
        for (i = 2; i < (int) x.size()-2; i += 4) {
            v.pb(mp(x[i],x[i+2]));
            if (i+3 < x.size()) v.pb(mp(x[i+1],x[i+3]));
        }
        b = query(v),v.clear();
        ans[0] = 0,ans[1] = 1;
        for (i = 2; i < x.size(); i++) {
            if ((i & 3) == 0) {
                if (b[i/2-2] == '0') ans[i] = 3^ans[i-1]^ans[i-2];
                else ans[i] = ans[i-2];
            }
            else if ((i & 3) == 1) {
                if (b[i/2-1] == '0') ans[i] = 3^ans[i-1]^ans[i-2];
                else ans[i] = ans[i-2];
            }
            else if ((i & 3) == 2) {
                if (a[i/2-1] == '0') ans[i] = 3^ans[i-1]^ans[i-2];
                else ans[i] = ans[i-2];
            }
            else {
                if (a[i/2] == '0') ans[i] = 3^ans[i-1]^ans[i-2];
                else ans[i] = ans[i-2];
            }
        }
        for (i = 0; i < x.size(); i++) {
            int e = (i == x.size()-1) ? n:x[i+1];
            for (j = x[i]; j < e; j++) sol[ans[i]].pb(j);
        }
        cout << "A " << sol[0].size() << " " << sol[1].size() << " " << sol[2].size() << endl;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < sol[i].size(); j++) cout << sol[i][j]+1 << " ";
            cout << endl,sol[i].clear();
        }
    }

    return 0;
}