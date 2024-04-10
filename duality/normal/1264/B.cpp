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

int ans[100000];
int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int i;
    if (a+b+c+d == 1) {
        printf("YES\n");
        if (a) printf("0");
        if (b) printf("1");
        if (c) printf("2");
        if (d) printf("3");
        printf("\n");
        return 0;
    }
    if ((a == 0) && (b == 0) && (abs(d-c) <= 1)) {
        if (d > c) {
            printf("YES\n");
            for (i = 0; i < d+c; i++) {
                if (i & 1) printf("2 ");
                else printf("3 ");
            }
            printf("\n");
        }
        else {
            printf("YES\n");
            for (i = 0; i < d+c; i++) {
                if (i & 1) printf("3 ");
                else printf("2 ");
            }
            printf("\n");
        }
        return 0;
    }
    if ((c == 0) && (d == 0) && (abs(a-b) <= 1)) {
        if (a > b) {
            printf("YES\n");
            for (i = 0; i < a+b; i++) {
                if (i & 1) printf("1 ");
                else printf("0 ");
            }
            printf("\n");
        }
        else {
            printf("YES\n");
            for (i = 0; i < a+b; i++) {
                if (i & 1) printf("0 ");
                else printf("1 ");
            }
            printf("\n");
        }
        return 0;
    }

    if (abs(a+c-b-d) > 1) {
        printf("NO\n");
        return 0;
    }
    if ((c >= d+1) && (b >= a+1) && (c-d == b-a)) {
        debug "here1";
        int x = 0;
        for (i = 0; i < a; i++) ans[x++] = 1,ans[x++] = 0;
        for (i = 0; i < c-d; i++) ans[x++] = 1,ans[x++] = 2;
        for (i = 0; i < d; i++) ans[x++] = 3,ans[x++] = 2;
        printf("YES\n");
        for (i = 0; i < a+b+c+d; i++) printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    if ((c >= d) && (b >= a+1) && (c-d == b-a-1)) {
        debug "here2";
        int x = 0;
        ans[x++] = 1;
        for (i = 0; i < a; i++) ans[x++] = 0,ans[x++] = 1;
        for (i = 0; i < c-d; i++) ans[x++] = 2,ans[x++] = 1;
        for (i = 0; i < d; i++) ans[x++] = 2,ans[x++] = 3;
        printf("YES\n");
        for (i = 0; i < a+b+c+d; i++) printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    if ((c >= d+1) && (b >= a) && (c-d-1 == b-a)) {
        debug "here3";
        int x = 0;
        for (i = 0; i < a; i++) ans[x++] = 0,ans[x++] = 1;
        for (i = 0; i < c-d-1; i++) ans[x++] = 2,ans[x++] = 1;
        for (i = 0; i < d; i++) ans[x++] = 2,ans[x++] = 3;
        ans[x++] = 2;
        printf("YES\n");
        for (i = 0; i < a+b+c+d; i++) printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    if ((c >= d) && (b >= a) && (c-d == b-a)) {
        debug "here4";
        int x = 0;
        for (i = 0; i < a; i++) ans[x++] = 0,ans[x++] = 1;
        for (i = 0; i < c-d; i++) ans[x++] = 2,ans[x++] = 1;
        for (i = 0; i < d; i++) ans[x++] = 2,ans[x++] = 3;
        printf("YES\n");
        for (i = 0; i < a+b+c+d; i++) printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    printf("NO\n");

    return 0;
}