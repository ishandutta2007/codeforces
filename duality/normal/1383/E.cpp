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

int dp[1000005][3],prev0[1000005],num0[1000005];
int best[1000005];
int bit[1000005],val[1000005];
int update(int i,int num,int N) {
    for (i++; i <= N; i += i & (-i)) bit[i] = (bit[i]+num) % MOD;
    return 0;
}
int query(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i],sum %= MOD;
    return sum;
}
int main() {
    string s;
    cin >> s;

    int i,j,l = -1;
    /*prev0[0] = (s[0] == '0') ? 0:-1;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') prev0[i] = i;
        else prev0[i] = prev0[i-1];
    }*/
    num0[s.size()] = 0;
    for (i = s.size()-1; i >= 0; i--) {
        if (s[i] == '1') num0[i] = 0;
        else num0[i] = 1+num0[i+1];
    }
    memset(best,-1,sizeof(best));
    int c = 0;
    LLI sum = 0;
    for (i = 0; i < s.size(); i++) {
        if (i == 0) {
            if (s[i] == '0') dp[i][0] = dp[i][2] = 1;
            else dp[i][1] = 1;
        }
        else {
            if (s[i] == '0') {
                dp[i][0] = (dp[i-1][0]+dp[i-1][1]) % MOD;
                if (l == -1) dp[i][0]++,dp[i][0] %= MOD;
                dp[i][1] = (l == -1) ? 0:dp[l][1];
                if (l != -1) dp[i][2] = ((LLI) dp[l][1]*(i-l)) % MOD;
                int c = i-l+1;
                dp[i][2] += query(s.size())-query(c-1);
                dp[i][2] %= MOD;/*
                for (j = c; best[j] != -1; j++) {
                    dp[i][2] += dp[best[j]][1];
                    //cout<<i<<"->"<<best[j]<<endl;
                }*/
                if (l != -1) dp[i][2] += num0[0];
                else dp[i][2] += i+1;
                dp[i][2] %= MOD;
            }
            else {
                if (i > 0) sum += dp[i-1][2],sum %= MOD;
                dp[i][0] = 0,dp[i][2] = dp[i-1][2];
                dp[i][1] = sum;
                /*for (j = i; j >= 0; j--) {
                    if (s[j] == '1') {
                        if (j > 0) dp[i][1] += dp[j-1][2];
                    }
                }*/
                dp[i][1] += c+1,dp[i][1] %= MOD;
            }
        }
        if (s[i] == '1') {
            if (l != -1) {
                for (j = 0; j <= num0[l+1]; j++) {
                    update(j,(dp[l][1]-val[j]+MOD) % MOD,s.size()+3);
                    best[j] = l,val[j] = dp[l][1];
                }
            }
            l = i,c++;
        }
        if (dp[i][0] < 0) dp[i][0] += MOD;
        if (dp[i][1] < 0) dp[i][1] += MOD;
        if (dp[i][2] < 0) dp[i][2] += MOD;
        //cout<<dp[i][0]<<","<<dp[i][1]<<","<<dp[i][2]<<endl;
    }
    printf("%d\n",(dp[s.size()-1][0]+dp[s.size()-1][1]) % MOD);

    return 0;
}