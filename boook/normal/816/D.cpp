/*input
4 3 7 5 2
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
#define MAX 200900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX] , gi[MAX] , ni[MAX];
void solveinit(){
	gi[0] = ni[0] = ni[1] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
}
int C(int a , int b){
	if(a < b) return 0;
	return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
vector<int> sol;
int32_t main(){
	solveinit();
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int tmp = (n % 4 == 0 ? n / 4 - 1 : n / 4);
	int les = tmp * 4;
	REP(i , 1 , n - les + 1){
		int now = i , cc = tmp * 2 , res = 0;
		for(int j = 0 ; now <= i + les ; j ++){
			res = (res + x[now] * C(cc , j)) % mod;
			// if(i == 1) cout << C(cc , j) << " ";
			now += 2;
		}
		sol.pb(res);
	}
	int xx = 1;
	while(sol.size() != 1){
	// for(auto to : sol) cout << to << " " ;cout << endl;
		vector<int> now;
		REP(j , 1 , sol.size()){
			now.pb((sol[j - 1] + xx * sol[j] + mod) % mod);
			xx = -xx;
		}
		sol = now;
	}
	cout << sol[0] << endl;
    return 0;
}