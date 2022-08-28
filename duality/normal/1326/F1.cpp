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

int n;
int adj[18][18];
vlli dp[1 << 14][14];/*
LLI findAns(int m,int c,int b) {
    if (dp[m][c].count(b)) return dp[m][c][b];
    if (m == (1 << c)) return 1;
    int i;
    LLI ans = 0;
    for (i = 0; i < n; i++) {
        if ((i != c) && (m & (1 << i)) && (adj[c][i] == (b & 1))) ans += findAns(m^(1 << c),i,b >> 1);
    }
    dp[m][c][b] = ans;
    return ans;
}*/
int main() {
    int i,j;
    char c;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf(" %c",&c),adj[i][j] = (c == '1');
    }

    int k,l;
    for (i = 1; i < (1 << n); i++) {
        //cout<<i<<endl;
        int b = 0;
        vi v;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) b++,v.pb(j);
        }
        for (j = 0; j < v.size(); j++) dp[i][v[j]].resize(1 << (b-1));
        if (b == 1) dp[i][v[0]][0] = 1;
        else {
            for (j = 0; j < v.size(); j++) {
                for (k = 0; k < v.size(); k++) {
                    if (k != j) {
                        for (l = 0; l < dp[i^(1 << v[j])][v[k]].size(); l++)
                            dp[i][v[j]][(l << 1) | adj[v[j]][v[k]]] += dp[i^(1 << v[j])][v[k]][l];
                    }
                }
            }
        }
        //for(j=0;j<v.size();j++){
        //    cout<<i<<","<<v[j]<<": ";
        //    printArr(dp[i][v[j]],dp[i][v[j]].size());
        //}
    }
    //debug "here";
    for (i = 0; i < (1 << (n-1)); i++) {
        LLI ans = 0;
        for (j = 0; j < n; j++) ans += dp[(1 << n)-1][j][i];
        printf("%I64d ",ans);
    }
    printf("\n");
    /*
    for (i = 0; i < (1 << (n-1)); i++) {
        LLI ans = 0;
        for (j = 0; j < n; j++) ans += findAns((1 << n)-1,j,i);
        if((i % 100)==0)cout<<i<<endl,printf("%I64d ",ans);
    }
    printf("\n");*/

    return 0;
}