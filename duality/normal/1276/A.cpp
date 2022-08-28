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

char s[150000];
int del[150000];
int main() {
    int i;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",s);

        int n = strlen(s),ans = 0;
        fill(del,del+n,0);
        for (i = 2; i < n-2; i++) {
            if ((s[i-2] == 't') && (s[i-1] == 'w') && (s[i] == 'o') && (s[i+1] == 'n') && (s[i+2] == 'e')) {
                del[i] = 1;
                ans++;
            }
        }
        for (i = 2; i < n; i++) {
            if (del[i] || del[i-1] || del[i-2]) continue;
            if ((s[i-2] == 'o') && (s[i-1] == 'n') && (s[i] == 'e')) del[i-1] = 1,ans++;
            if ((s[i-2] == 't') && (s[i-1] == 'w') && (s[i] == 'o')) del[i-1] = 1,ans++;
        }
        printf("%d\n",ans);
        for (i = 0; i < n; i++) {
            if (del[i]) printf("%d ",i+1);
        }
        printf("\n");
    }

    return 0;
}