#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 110
#define INF 0x3f3f3f3f
#define mod 1000000007LL

typedef vector<vector<int>> V;

int n , m;
int cnt[MAX] , dp[MAX];
V cross(V a , V b){
    V ans(MAX , vector<int>(MAX));
    REP(i , 1 , 102) REP(j , 1 , 102){
        REP(k , 1 , 102){
            ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
    return ans;
}
V ppow(V now , int k){
    if(k == 1) return now;
    else if(k % 2 == 0) return ppow(cross(now , now) , k / 2);
    else if(k % 2 == 1) return cross(ppow(cross(now , now) , k / 2) , now);
}
V x(MAX , vector<int>(MAX));
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) {
        int tmp;
        cin >> tmp , cnt[tmp]++;
    }
    if(m == 0) return puts("1");
    // else if(m == 1) {
    //     cout << cnt[1] + 1 << endl;
    //     return 0;
    // }
    else {
        REP(i , 1 , 100) x[i][i + 1] = 1;
        REP(i , 1 , 101) x[100][101 - i] = cnt[i];
        x[101][1] = 1 , x[101][101] = 1;
        V ans = ppow(x , m);
        dp[0] = 1;
        REP(i , 1 , 101){
            REP(j , 1 , i + 1) dp[i] = (dp[i] + dp[i - j] * cnt[j]) % mod;
            // cout << dp[i] << " ";
        }
            // cout << endl;
        dp[101] = 1;
        int res = 0;
        REP(i , 1 , 102) res = (res + dp[i] * ans[101][i]) % mod;
        cout << res << endl;
    }
    return 0;
}