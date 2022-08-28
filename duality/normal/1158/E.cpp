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

int d[1000],q[1000],l[1000],r[1000],p[1000];
vi dd[1000];
int main() {
    int n;
    cin >> n;

    int i,j;
    fill(d,d+n,-1);
    d[0] = 0,dd[0].pb(0);
    int x = 0,z;
    while ((1 << x) < n) x++;
    for (i = 1; i < n; i++) l[i] = 1,r[i] = (1 << x)-1;
    for (; x >= 1; x--) {
        for (z = 0; z < 2; z++) {
            for (i = 0; i < n; i++) q[i] = 0;
            for (i = (z << x); i < n; i += (1 << (x+1))) {
                for (j = 0; j < dd[i].size(); j++) q[dd[i][j]] = (1 << (x-1));
            }
            string s,s2;
            cout << "?";
            for (i = 0; i < n; i++) cout << " " << q[i];
            cout << endl;
            cin >> s;
            cout << "?";
            for (i = 0; i < n; i++) {
                if (q[i] > 0) q[i]--;
                cout << " " << q[i];
            }
            cout << endl;
            cin >> s2;
            for (i = 0; i < n; i++) {
                if ((d[i] != -1) || (((l[i] >> x) & 1) != z)) continue;
                if (s[i] != s2[i]) d[i] = (l[i]+r[i])/2,dd[d[i]].pb(i);
                else if (s[i] == '1') r[i] = (l[i]+r[i])/2-1;
                else l[i] = (l[i]+r[i])/2+1;
            }
        }
    }
    for (z = 0; z < 3; z++) {
        vi v;
        for (i = 0; i < n; i++) {
            if ((d[i] % 3) == z) v.pb(i);
        }
        for (i = 0; (1 << i) < v.size(); i++) {
            for (j = 0; j < n; j++) q[j] = 0;
            for (j = 0; j < v.size(); j++) {
                if (j & (1 << i)) q[v[j]] = 1;
            }
            string s;
            cout << "?";
            for (j = 0; j < n; j++) cout << " " << q[j];
            cout << endl;
            cin >> s;
            for (j = 0; j < n; j++) {
                if (((d[j] % 3) == ((z+1) % 3)) && (s[j] == '1')) p[j] |= (1 << i);
            }
        }
        for (i = 0; i < n; i++) {
            if ((i > 0) && ((d[i] % 3) == ((z+1) % 3))) p[i] = v[p[i]];
        }
    }
    cout << "!" << endl;
    for (i = 1; i < n; i++) cout << p[i]+1 << " " << i+1 << endl;

    return 0;
}