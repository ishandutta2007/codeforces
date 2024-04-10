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
#define MAX 100008
#define INF 0x3f3f3f3f

int n , x[MAX] , ans[MAX];
VI v , g[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , n) cin >> x[i];
	REP(i , n){
		if(v.empty() || v.back() < x[i]){
			v.pb(x[i]);
			g[v.size()].pb(i);
		}
		else {
			int po = lower_bound(ALL(v) , x[i]) - v.begin();
			v[po] = x[i];
			g[po + 1].pb(i);
		}
	}
	int mm = v.size();
	//       211121111133212111311131
	// ans = 211121111133212111311131


	if(g[mm].size() == 1) { for(auto i : g[mm]) ans[i] = 3;}
	else { for(auto i : g[mm]) ans[i] = 2; }

	RREP(i , mm - 1 , 0){
		deque<int> dq;
		int qqsum = 0;
		int apo = g[i + 1].size() - 1;
		RREP(j , g[i].size() - 1 , 0){
			int now = g[i][j];
			while(apo >= 0 && g[i + 1][apo] > now){
				if(ans[g[i + 1][apo]] == 0) ;
				else dq.push_front(g[i + 1][apo]);
				apo--;
			}
			while(dq.size() && x[dq.back()] <= x[now]) dq.pop_back();
			if(dq.size()) ans[now] = 2 , qqsum ++;
		}
		if(qqsum == 1) {
			RREP(j , g[i].size() - 1 , 0){
				int now = g[i][j];
				if(ans[now] == 2) ans[now] = 3;
			}
		}
	}
	REP(i , n){
		if(ans[i] == 0) ans[i] = 1;
		cout << ans[i];
	}
	cout << endl;
    return 0;
}