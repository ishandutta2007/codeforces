#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> PII;
typedef unsigned long long int LL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
///---------------------------
#define MAX 1000
#define INF 1000000000000000000LL
//#define INF 0x3f3f3f3f
#define debug 1

LL ppow(LL a , LL b){
    if(b == 0)return 1;
    else if(b & 1){
        LL ans = ppow(a * a , b / 2) * a;
        if(ans >= INF)return INF;
        return ans;
    }
    else {
        LL ans = ppow(a * a , b / 2);
        if(ans >= INF)return INF;
        return ans;
    }
}
LL n;
string s;
LL dp[MAX][MAX];
int main(){

    while(cin >> n >> s){
        REP(i , MAX) REP(j , MAX) dp[i][j] = INF;
        RREP(i , s.size() - 1 , 0){
            LL sum = 0;
            REPNM(j , i , s.size()){
                sum = sum * 10 + s[j] - '0';
                if(sum >= n)break;
                if(sum == 0){
                    if(j == s.size() - 1){
                        dp[i][0] = min(dp[i][0] , sum);
                    }
                    REP(k , s.size()){
                        if(sum * ppow(n , k + 1) >= INF)break;
                        if(sum * ppow(n , k + 1) >= dp[i][k + 1])break;
                        dp[i][k + 1] = min(dp[i][k + 1] , dp[j + 1][k] + sum * ppow(n , k + 1));
                    }
                    break;
                }
                if(j == s.size() - 1){
                    dp[i][0] = min(dp[i][0] , sum);
                }
                else {

                    REP(k , s.size()){
                        if(sum * ppow(n , k + 1) > INF)break;
                        if(sum * ppow(n , k + 1) >= dp[i][k + 1])break;
                        dp[i][k + 1] = min(dp[i][k + 1] , dp[j + 1][k] + sum * ppow(n , k + 1));
                    }
                }
            }
//            REP(qq , s.size())printf("dp[%1d][%d] = %lld\n",i,qq,dp[i][qq]);
        }
        LL ans = dp[0][0];
        REP(i , s.size()) ans = min(ans , dp[0][i]);
        cout << ans << endl;
    }
    return 0;
}