#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define int long long
#define MAX 100900
#define mod 998244353LL

int n , x[MAX];
map<int , int> cc;
vector<int> sol;
void solve(int i){
	RREP(idx , 4 , 2){
		int now = 0;
		RREP(j , 40 , 0){
			int to = now + (1ll << j);
			if(idx == 4 && x[i] / to / to / to / to >= 1) now = to;
			if(idx == 3 && x[i] / to / to / to >= 1) now = to;
			if(idx == 2 && x[i] / to / to >= 1) now = to;
		}
		if(idx == 4 && now * now * now * now == x[i])
			return cc[now] += 4 , x[i] = 1 , sol.push_back(now) , void();
		if(idx == 3 && now * now * now == x[i])
			return cc[now] += 3 , x[i] = 1 , sol.push_back(now) , void();
		if(idx == 2 && now * now == x[i])
			return cc[now] += 2 , x[i] = 1 , sol.push_back(now) , void();
	}
}
int32_t main(){
	cin.tie(0) , cout.sync_with_stdio(0);
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) solve(i);

	REP(i , 1 , n + 1) REP(j , i + 1 , n + 1)
		if(x[i] != 1 && x[j] != 1 && x[i] != x[j] && __gcd(x[i] , x[j]) != 1)
			sol.push_back(__gcd(x[i] , x[j]));

	REP(i , 1 , n + 1) if(x[i] != 1){
		for(auto to : sol){
			if(x[i] > to && x[i] % to == 0){
				cc[x[i] / to] ++;
				cc[to] ++;
				x[i] = 1;
			}
		}
	}
	// REP(i , 1 , n + 1) cout << x[i] << " ";  cout << endl;
	map<int , int> las;
	REP(i , 1 , n + 1) if(x[i] != 1) las[x[i]] ++;

	int ans = 1;
	for(auto to : cc){
		ans = (ans * (to.second + 1)) % mod;
	}
	// cout << "now ans = " << ans << endl;
	for(auto to : las){
		ans = (ans * (to.second + 1)) % mod;
		ans = (ans * (to.second + 1)) % mod;
	}
	cout << ans << endl;
	return 0;
}