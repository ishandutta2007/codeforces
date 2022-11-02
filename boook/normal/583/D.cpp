#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
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
#define MAX 150
#define INF 0x3f3f3f3f


LL n , k , x[MAX] , m[MAX][MAX] , res[MAX][MAX] , r[MAX][MAX] , tmp[MAX][MAX];
void ppow(){
	MEM(r , 0);
	REP(i , n) REP(j , n) res[i][j] = m[i][j];

	while(k){
		if(k & 1){ // r = r * res
			REP(i , n) REP(j , n){
				tmp[i][j] = -INF;
				REP(k , n) tmp[i][j] = max(tmp[i][j] , r[i][k] + res[k][j]);
			}
			REP(i , n) REP(j , n) r[i][j] = tmp[i][j];
		}

		REP(i , n) REP(j , n){
			tmp[i][j] = -INF;
			REP(k , n) tmp[i][j] = max(tmp[i][j] , res[i][k] + res[k][j]);
		}
		REP(i , n) REP(j , n) res[i][j] = tmp[i][j];
		k >>= 1;
	}

}
int main(){
    RLL(n , k);
    REP(i , n) RL(x[i]);

    REP(i , n){
    	REP(j , n){
    		if(x[i] > x[j]) m[i][j] = -INF;
    		else {
    			m[i][j] = 1;
    			REP(k , j) if(x[k] <= x[j])
    				m[i][j] = max(m[i][j] , m[i][k] + 1);
    		}
    	}
    }
    LL ans = 0;
    ppow();
    REP(i , n) REP(j , n) ans = max(ans , r[i][j]);
    printf("%lld\n", ans);
    return 0;
}