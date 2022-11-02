/*input
100
94 22 24 99 58 97 20 29 67 30 38 64 77 50 15 44 92 88 39 42 25 70 2 76 84 6 37 49 17 71 31 19 26 79 10 35 65 63 32 95 5 8 52 27 83 18 53 93 13 81 48 68 54 82 34 60 87 23 16 86 55 40 61 45 28 7 74 41 14 91 3 72 33 11 98 89 90 69 78 36 80 59 56 21 43 1 75 46 47 12 96 73 57 51 4 85 9 100 66 62
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , x[MAX] , use[MAX] , ans[MAX];
vector<int> v[MAX];
int trs(int now , int mod){
	return (now % mod + mod) % mod;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) if(use[i] == 0){
		int now = i;
		vector<int> sol;
		while(use[now] == 0) use[now] = 1 , sol.pb(now) , now = x[now];
		if(sol.size() % 2 == 1){
			REP(j , 0 , sol.size()){
				ans[sol[j]] = sol[trs(j - sol.size() / 2 , sol.size())];
			}
		}
		else {
			if(v[sol.size()].size() == 0) v[sol.size()] = sol;
			else {
				int id = sol.size();
				REP(j , 0 , sol.size()){
					ans[sol[j]] = v[id][j];
					ans[v[id][j]] = sol[trs(j + 1 , sol.size())];
				}
				v[id].clear();
			}
		}
	}
	REP(i , 1 , n + 1) if(v[i].size()) return cout << -1 << endl , 0;
	REP(i , 1 , n + 1) cout << ans[i] << " ";
	cout << endl;
    return 0;
}