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

LLI l[100000];
LLI suff[100000],ss[100001],grass[100000];
char s[100000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d",&l[i]);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);

    int w = 0;
    LLI t = 0,st = 0;
    for (i = n-1; i >= 0; i--) {
        suff[i] = ((i == n-1) ? 0:suff[i+1])+l[i];
        grass[i] = ((i == n-1) ? 0:grass[i+1])+((s[i] == 'G') ? l[i]:0);
    }
    ss[n] = 0;
    for (i = n-1; i >= 0; i--) {
        if (s[i] == 'L') ss[i] = ss[i+1]+l[i];
        else ss[i] = max(ss[i+1]-l[i],0LL);
    }
    for (i = 0; i < n; i++) {
        if (s[i] == 'L') {
            LLI need = max(l[i]-st,0LL);
            if (w) t += 3*need,st += need;
            else t += 5*need,st += need;
            t += l[i],st -= l[i];
        }
        else {
            if (s[i] == 'W') w = 1;
            int tt = (s[i] == 'W') ? 3:5;
            if (st+l[i] > ss[i+1]) {
                if (s[i] == 'G') {
                    if (st > l[i]+ss[i+1]) st -= l[i],t += l[i];
                    else {
                        LLI u = (ss[i+1]+l[i]-st)*tt+(l[i]+st-ss[i+1]);
                        t += u/2;
                        st = ss[i+1];
                    }
                }
                else {
                    if (2*l[i] >= suff[i]-st) {
                        LLI u = (suff[i]-st)*tt+(suff[i]+st);
                        t += u/2;
                        break;
                    }
                    else t += tt*l[i],st += l[i];
                }
            }
            else t += tt*l[i],st += l[i];
        }
    }
    printf("%I64d\n",t);

    return 0;
}