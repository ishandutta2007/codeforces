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
#define MAX 3050
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}

void Read(){}

void Solve(){}
vector<LL> v[MAX];
LL two[MAX][MAX];
LL n , m;
int main(){
	RLL(n , m);
	LL q , w;
	REP(i , m){
		RLL(q , w);
		v[q].pb(w);
	}
	REPNM(i , 1 , n + 1){
		for(auto j : v[i]){
			for(auto k : v[j]) two[i][k] ++;
		}
	}
	LL ans = 0;
	REPNM(i , 1 , n + 1){
		REPNM(j , 1 , n + 1){
			if(i == j) continue;
			ans += two[i][j] * (two[i][j] - 1) / 2;
		}
	}
	cout << ans << endl;
    return 0;
}