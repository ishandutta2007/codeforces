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

int a[100],seen[101];
int ways[101][10001];
bitset<10001> poss[101];
int main() {
    int i;
    int n,d = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),d += (seen[a[i]] == 0),seen[a[i]]++;
    if (d <= 2) {
        printf("%d\n",n);
        return 0;
    }

    int j;/*
    ways[0][0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= 10000; j++) {
            ways[i+1][j] = ways[i][j];
            if (j >= a[i]) ways[i+1][j] += ways[i][j-a[i]];
            ways[i+1][j] = min(ways[i+1][j],2);
        }
    }
    if (d == 2) {
        int m = 1e9;
        for (i = 0; i < n; i++) m = min(m,a[i]);
        if (ways[n][m*seen[m]] == 1) {
            printf("%d\n",n);
            return 0;
        }
    }*/
    int k;
    int ans = 1;
    for (i = 1; i <= 100; i++) {
        if (seen[i] > 1) {
            vi v;
            for (j = 0; j < n; j++) {
                if (a[j] != i) v.pb(a[j]);
            }
            for (j = 0; j <= v.size(); j++) poss[j].reset();
            poss[0][0] = 1;
            for (j = 0; j < v.size(); j++) {
                for (k = j+1; k > 0; k--) poss[k] |= poss[k-1] << v[j];
            }
            printArr(v,v.size());
            /*
            memset(ways,0,sizeof(ways));
            ways[0][0] = 1;
            int sum = 0;
            for (j = 0; j < v.size(); j++) {
                sum += v[j];
                for (k = 0; k <= sum; k++) {
                    ways[j+1][k] = ways[j][k];
                    if (k >= v[j]) ways[j+1][k] += ways[j][k-v[j]];
                    ways[j+1][k] = min(ways[j+1][k],2);
                }
            }*/
            for (j = 1; j <= seen[i]; j++) {
                if (!poss[j][j*i]) ans = max(ans,j);
                else break;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}