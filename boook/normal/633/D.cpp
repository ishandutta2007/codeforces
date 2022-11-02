/*input
5
1 1 0 1 -1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX];
map<int , vector<int>> cc;
set<PII> use;
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc[x[i]].pb(i);
	int ans = 0;
	REP(i , 1 , n + 1){
		REP(j , i + 1 , n + 1){
			if(use.find(mp(x[i] , x[j])) != use.end()) continue;
			map<int , int> sol , did;
			int cnt = 2 , fr = i , ba = j , now = x[fr] + x[ba];
			did[i] = did[j] = 1;
			use.insert(mp(x[i] , x[j]));
			while(cc.find(now) != cc.end()){
				if(sol.find(now) != sol.end() && sol[now] == cc[now].size()) break;
				if(did[cc[now][sol[now]]]) sol[now] ++;
				else {
					did[cc[now][sol[now]]] = 1;
					use.insert(mp(x[ba] , now));
					fr = ba , ba = cc[now][sol[now]] , now = x[fr] + x[ba];
					cnt ++;
				}
			}
			fr = i , ba = j , now = x[ba] - x[fr];
			while(cc.find(now) != cc.end()){
				if(sol.find(now) != sol.end() && sol[now] == cc[now].size()) break;
				if(did[cc[now][sol[now]]]) sol[now] ++;
				else {
					did[cc[now][sol[now]]] = 1;
					use.insert(mp(now , x[fr]));
					ba = fr , fr = cc[now][sol[now]] , now = x[ba] - x[fr];
					cnt ++;
				}
			}
			ans = max(ans , cnt);
		}
	}
	cout << ans << endl;
    return 0;
}