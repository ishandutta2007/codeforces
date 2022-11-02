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
#define MAX 150090
#define INF 0x3f3f3f3f
#define debug 1

LL n , m;
vector<int> v[MAX] , tmp;
int use[MAX];
void DFS(int now){
	if(use[now]) return ;
	use[now] = 1;
	tmp.pb(now);
	REP(i , v[now].size()){
		DFS(v[now][i]);
	}
} 
int main(){

	while(cin >> n >> m){
		REP(i , m){
			int q , w;
			RII(q , w);
			v[q].pb(w);
			v[w].pb(q);
		}
		int ok = 1;
		REPNM(i , 1 , n + 1){
			tmp.clear();
			if(!use[i]){
				DFS(i);
			}
			LL sum = tmp.size();
			LL tt = LL(sum - 1);
			for(auto j : tmp){
				if(v[j].size() != tt) ok = 0;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	
    return 0;
}