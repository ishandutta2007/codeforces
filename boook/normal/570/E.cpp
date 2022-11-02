#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 510
#define INF 0x3f3f3f3f
#define mod 1000000007

int n , m;
string p[MAX];
int dp[2][MAX][MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , n) cin >> p[i];
    if(p[0][0] != p[n - 1][m - 1]) return puts("0") * 0;
    else {
        dp[0][0][n - 1] = 1;
        int e = 0 , step , qq = n + m - 1 , ans = 0;
        if(qq & 1) step = qq / 2 + 1;
        else step = qq / 2;
        REPNM(i , 1 , step){
            ans = 0;
            REP(j , i + 1){
                REP(k , i + 1){
                    PII q = mp(j , i - j);
                    PII w = mp(n - 1 - k , n - 2 + m - (n - 1 - k) - i);

                    if(q.A < 0 || q.A >= n || q.B < 0 || q.B >= m) continue;
                    if(w.A < 0 || w.A >= n || w.B < 0 || w.B >= m) continue;
                    dp[e ^ 1][q.A][w.A] = 0;
                    if(p[q.A][q.B] != p[w.A][w.B]) continue;
                    
                    if(q.A != 0) dp[e ^ 1][q.A][w.A] = dp[e][q.A - 1][w.A] + dp[e][q.A - 1][w.A + 1];
                    dp[e ^ 1][q.A][w.A] += dp[e][q.A][w.A] + dp[e][q.A][w.A + 1] ;
                    dp[e ^ 1][q.A][w.A] %= mod;

                    if(q.A == w.A) ans = (ans + dp[e ^ 1][q.A][w.A]) % mod;
                    else if(q.A + 1 == w.A && qq % 2 == 0) ans = (ans + dp[e ^ 1][q.A][w.A]) % mod;
                    // DB4(q.A , q.B , w.A , w.B);
                    // printf("dp[%lld][%lld][%lld] = %lld\n", i , q.A , w.A , dp[e ^ 1][q.A][w.A]);
                    // cout << "----" << endl;
                }
            }
            e = 1 - e;
        }
        cout << ans << endl;
    }
    return 0;
}