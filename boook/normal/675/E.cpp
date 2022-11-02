#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f
#define debug 1

void Solve(){}
LL n , x[MAX] , dp[MAX];
PLL b[MAX * 4];
void Build(LL now , LL l , LL r){
    if(l == r) { b[now] = mp(x[l] , -l); return ; }
    LL ls = now * 2 , rs = now * 2 + 1 , mid = (l + r) / 2;
    Build(ls , l , mid) , Build(rs , mid + 1 , r);
    b[now] = max(b[ls] , b[rs]);
}
PII Query(LL now , LL l , LL r , LL ql , LL qr){
    if(ql <= l && r <= qr) return b[now];
    LL ls = now * 2 , rs = now * 2 + 1 , mid = (l + r) / 2;
    if(qr <= mid) return Query(ls , l , mid , ql , qr);
    if(mid + 1 <= ql) return Query(rs , mid + 1 , r , ql , qr);
    return max(Query(ls , l , mid , ql , mid) , Query(rs , mid + 1 , r , mid + 1 , qr));
}


int main(){
    RL(n);
    LREPNM(i , 1LL , n) RL(x[i]);
    x[n] = n;

    Build(1LL , 1LL , n);

    LL ans = 0;
    RREP(i , n - 1LL , 1LL){
        // DBGG(i + 1LL , x[i]);
        LL tmp = -Query(1LL , 1LL , n , i + 1LL , x[i]).B;
        dp[i] = dp[tmp] + n - i - (x[i] - tmp);
        ans += dp[i];
        // DBGG("tmp = " , tmp);
        // DBGG("i = " , dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}