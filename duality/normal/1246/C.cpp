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
#define MOD 1000000007

char grid[2005][2005];
int preG[2005][2005];
int query(int l,int r,int u,int d) {
    return preG[r+1][d+1]-preG[l][d+1]-preG[r+1][u]+preG[l][u];
}
LLI dp[2005][2005][2];
LLI pre[2005][2005][2];
LLI query2(int l,int r,int u,int d,int t) {
    //cout<<"query2 "<<l<<","<<r<<","<<u<<","<<d<<","<<t<<endl;
    //cout<<"ret "<<pre[r+1][d+1][t]-pre[l][d+1][t]-pre[r+1][u][t]+pre[l][u][t]<<endl;
    return pre[r+1][d+1][t]-pre[l][d+1][t]-pre[r+1][u][t]+pre[l][u][t];
}
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %c",&grid[i][j]);
            preG[i+1][j+1] = preG[i][j+1] + preG[i+1][j] - preG[i][j] + (grid[i][j] == 'R');
        }
    }
    if (grid[n-1][m-1] == 'R') {
        printf("0\n");
        return 0;
    }

    for (i = n-1; i >= 0; i--) {
        for (j = m-1; j >= 0; j--) {
            int x = query(i,n-1,j,j);
            dp[i][j][0] = query2(i,n-1-x,j+1,j+1,1);
            if ((x == 0) && (j == m-1)) dp[i][j][0]++;
            x = query(i,i,j,m-1);
            dp[i][j][1] = query2(i+1,i+1,j,m-1-x,0);
            if ((x == 0) && (i == n-1)) dp[i][j][1]++;
            dp[i][j][0] = (dp[i][j][0]+MOD) % MOD;
            dp[i][j][1] = (dp[i][j][1]+MOD) % MOD;
            pre[i][j][0] = pre[i+1][j][0] + pre[i][j+1][0] - pre[i+1][j+1][0] + dp[i][j][0];
            pre[i][j][1] = pre[i+1][j][1] + pre[i][j+1][1] - pre[i+1][j+1][1] + dp[i][j][1];
            pre[i][j][0] = (pre[i][j][0]+MOD) % MOD;
            pre[i][j][1] = (pre[i][j][1]+MOD) % MOD;
            //cout<<pre[i][j][0]<<","<<pre[i][j][1]<<" ";
        }//cout<<endl;
    }
    dp[0][0][0] = ((dp[0][0][0] % MOD)+MOD) % MOD;
    dp[0][0][1] = ((dp[0][0][1] % MOD)+MOD) % MOD;
    assert(dp[0][0][0] == dp[0][0][1]);
    printf("%d\n",(int) dp[0][0][0]);

    return 0;
}