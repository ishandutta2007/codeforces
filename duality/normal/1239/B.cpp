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

char s[300000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);

    int c1 = 0,c2 = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') c1++;
        else c2++;
    }
    if (c1 != c2) {
        printf("0\n1 1\n");
        return 0;
    }
    int m = 0,mi = -1,c = 0,x = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') c++;
        else c--;
        if (c < m) m = c,mi = i;
    }
    rotate(s,s+mi+1,s+n);

    int cc = 0,p = -1;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') c++;
        else c--;
        if (c == 0) x++;
    }
    int mm = x,ma = 0,mb = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') c++;
        else c--;
        if (c == 0) {
            if (cc > mm) mm = cc,ma = p+1,mb = i;
            cc = 0,p = i;
        }
        else if (c == 1) cc++;
    }
    p = -1;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') c++;
        else c--;
        if (c == 1) {
            if ((s[i] == ')') && (cc+x > mm)) mm = cc+x,ma = p+2,mb = i;
            cc = 0,p = i-1;
        }
        else if (c == 2) cc++;
    }
    printf("%d\n",mm);
    printf("%d %d\n",((mi+ma+1) % n)+1,((mi+mb+1) % n)+1);

    return 0;
}