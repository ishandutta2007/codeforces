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

char grid[300000];
char s[4],best[4];
int f;
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i*m+j]);
    }

    int ans = n*m;
    s[0] = 'A',s[1] = 'C',s[2] = 'G',s[3] = 'T';
    do {
        int sum = 0;
        for (i = 0; i < n; i++) {
            int a = 0,b = 0;
            for (j = 0; j < m; j++) {
                if (i & 1) {
                    if (j & 1) a += (grid[i*m+j] != s[0]),b += (grid[i*m+j] != s[1]);
                    else a += (grid[i*m+j] != s[1]),b += (grid[i*m+j] != s[0]);
                }
                else {
                    if (j & 1) a += (grid[i*m+j] != s[2]),b += (grid[i*m+j] != s[3]);
                    else a += (grid[i*m+j] != s[3]),b += (grid[i*m+j] != s[2]);
                }
            }
            sum += min(a,b);
        }
        if (sum < ans) ans = sum,copy(s,s+4,best),f = 0;
        sum = 0;
        for (i = 0; i < m; i++) {
            int a = 0,b = 0;
            for (j = 0; j < n; j++) {
                if (i & 1) {
                    if (j & 1) a += (grid[j*m+i] != s[0]),b += (grid[j*m+i] != s[1]);
                    else a += (grid[j*m+i] != s[1]),b += (grid[j*m+i] != s[0]);
                }
                else {
                    if (j & 1) a += (grid[j*m+i] != s[2]),b += (grid[j*m+i] != s[3]);
                    else a += (grid[j*m+i] != s[3]),b += (grid[j*m+i] != s[2]);
                }
            }
            sum += min(a,b);
        }
        if (sum < ans) ans = sum,copy(s,s+4,best),f = 1;
    } while (next_permutation(s,s+4));
    copy(best,best+4,s);
    if (f == 0) {
        for (i = 0; i < n; i++) {
            int a = 0,b = 0;
            for (j = 0; j < m; j++) {
                if (i & 1) {
                    if (j & 1) a += (grid[i*m+j] != s[0]),b += (grid[i*m+j] != s[1]);
                    else a += (grid[i*m+j] != s[1]),b += (grid[i*m+j] != s[0]);
                }
                else {
                    if (j & 1) a += (grid[i*m+j] != s[2]),b += (grid[i*m+j] != s[3]);
                    else a += (grid[i*m+j] != s[3]),b += (grid[i*m+j] != s[2]);
                }
            }
            if (a < b) {
                for (j = 0; j < m; j++) {
                    if (i & 1) {
                        if (j & 1) grid[i*m+j] = s[0];
                        else grid[i*m+j] = s[1];
                    }
                    else {
                        if (j & 1) grid[i*m+j] = s[2];
                        else grid[i*m+j] = s[3];
                    }
                }
            }
            else {
                for (j = 0; j < m; j++) {
                    if (i & 1) {
                        if (j & 1) grid[i*m+j] = s[1];
                        else grid[i*m+j] = s[0];
                    }
                    else {
                        if (j & 1) grid[i*m+j] = s[3];
                        else grid[i*m+j] = s[2];
                    }
                }
            }
        }
    }
    else {
        for (i = 0; i < m; i++) {
            int a = 0,b = 0;
            for (j = 0; j < n; j++) {
                if (i & 1) {
                    if (j & 1) a += (grid[j*m+i] != s[0]),b += (grid[j*m+i] != s[1]);
                    else a += (grid[j*m+i] != s[1]),b += (grid[j*m+i] != s[0]);
                }
                else {
                    if (j & 1) a += (grid[j*m+i] != s[2]),b += (grid[j*m+i] != s[3]);
                    else a += (grid[j*m+i] != s[3]),b += (grid[j*m+i] != s[2]);
                }
            }
            if (a < b) {
                for (j = 0; j < n; j++) {
                    if (i & 1) {
                        if (j & 1) grid[j*m+i] = s[0];
                        else grid[j*m+i] = s[1];
                    }
                    else {
                        if (j & 1) grid[j*m+i] = s[2];
                        else grid[j*m+i] = s[3];
                    }
                }
            }
            else {
                for (j = 0; j < n; j++) {
                    if (i & 1) {
                        if (j & 1) grid[j*m+i] = s[1];
                        else grid[j*m+i] = s[0];
                    }
                    else {
                        if (j & 1) grid[j*m+i] = s[3];
                        else grid[j*m+i] = s[2];
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) printf("%c",grid[i*m+j]);
        printf("\n");
    }

    return 0;
}