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

int a[2000],b[2000];
int pos[10][10][10][10];
int dp[2001][9][1430];
int findAns(int c,int p,int e[4],int n) {
    sort(e,e+4);
    int &ans = dp[c][p][pos[e[0]][e[1]][e[2]][e[3]]];
    if ((e[0] == 9) && (c == n)) return 0;
    else if (ans != -1) return ans;
    int i,j;
    ans = 999999;
    for (i = 0; i < 9; i++) {
        if (i != p) {
            int toadd = abs(i-p);
            int e2[4];
            copy(e,e+4,e2);
            for (j = 0; j < 4; j++) {
                if (e2[j] == i) e2[j] = 9,toadd++;
            }
            int c2 = c;
            while ((c2 < n) && (a[c2] == i)) {
                for (j = 0; j < 4; j++) {
                    if (e2[j] == 9) {
                        e2[j] = b[c2],toadd++;
                        break;
                    }
                }
                if (j == 4) break;
                else c2++;
            }
            sort(e,e+4);
            if (toadd > abs(i-p)) ans = min(ans,findAns(c2,i,e2,n)+toadd);
        }
    }
    return ans;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&a[i],&b[i]),a[i]--,b[i]--;

    int j,k,l;
    int c = 0;
    for (i = 0; i < 10; i++) {
        for (j = i; j < 10; j++) {
            for (k = j; k < 10; k++) {
                for (l = k; l < 10; l++) pos[i][j][k][l] = c++;
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    int e[4];
    e[0] = e[1] = e[2] = e[3] = 9;
    c = 0;
    while ((c < n) && (a[c] == 0)) {
        for (j = 0; j < 4; j++) {
            if (e[j] == 9) {
                e[j] = b[c];
                break;
            }
        }
        if (j == 4) break;
        else c++;
    }
    printf("%d\n",findAns(c,0,e,n)+c);

    return 0;
}