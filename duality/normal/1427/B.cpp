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

char s[100000];
int score(int n) {
    int i,ss = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if ((i > 0) && (s[i-1] == 'W')) ss += 2;
            else ss++;
        }
    }
    return ss;
}
int main() {
    int i;
    int t,n,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&k);
        int alll = 1;
        for (i = 0; i < n; i++) scanf(" %c",&s[i]),alll &= (s[i] == 'L');
        if (k == 0) {
            printf("%d\n",score(n));
            continue;
        }
        if (alll) s[0] = 'W',k--;

        int p = -1;
        vi v;
        for (i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (p != -1) v.pb(i-p-1);
                p = i;
            }
        }
        int x = 0;
        for (i = 0; i < n; i++) x += (s[i] == 'L');
        k = min(k,x);
        sort(v.begin(),v.end());
        int ss = score(n);
        for (i = 0; i < v.size(); i++) {
            if (v[i] == 0) continue;
            if (k < v[i]) {
                ss += 2*k;
                k = 0;
                break;
            }
            else {
                ss += 2*v[i]+1;
                k -= v[i];
            }
        }
        if (k > 0) ss += 2*k;
        printf("%d\n",ss);
    }

    return 0;
}