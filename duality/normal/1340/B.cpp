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

string arr[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", \
    "1101011", "1101111", "1010010", "1111111", "1111011"};
int arr2[10],bb[10];
char s[2000][8];
int poss[2001][2001];
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%s",s[i]);

    int j,l;
    poss[n][0] = 1;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 7; j++) {
            if (arr[i][j] == '1') arr2[i] |= (1 << j),bb[i]++;
        }
    }
    for (i = n-1; i >= 0; i--) {
        int c = 0,b = 0;
        for (j = 0; j < 7; j++) {
            if (s[i][j] == '1') c |= (1 << j),b++;
        }
        for (j = 0; j <= k; j++) {
            for (l = 0; l < 10; l++) {
                if ((arr2[l] & c) == c) {
                    if ((j >= bb[l]-b) && poss[i+1][j-(bb[l]-b)]) {
                        poss[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    if (!poss[0][k]) printf("-1\n");
    else {
        int u = k;
        for (i = 0; i < n; i++) {
            int c = 0,b = 0;
            for (j = 0; j < 7; j++) {
                if (s[i][j] == '1') c |= (1 << j),b++;
            }
            for (j = 9; j >= 0; j--) {
                if ((arr2[j] & c) == c) {
                    if ((u >= bb[j]-b) && poss[i+1][u-(bb[j]-b)]) {
                        u -= bb[j]-b;
                        break;
                    }
                }
            }
            printf("%d",j);
        }
        printf("\n");
    }

    return 0;
}