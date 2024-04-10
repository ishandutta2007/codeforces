/*input
3
4
7 2 2 7
8
2 8 1 4 8 2 1 5
5
5 5 5 5 5
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
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f

int solve(PII x , PII y){
	return x.A * y.B >= y.A * x.B;
}
int t , n , x[MAX];
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 0 , t){
		cin >> n;
		REP(i , 1 , n + 1) cin >> x[i];
		sort(x + 1 , x + 1 + n);
		vector<int> v;
		REP(i , 2 , n + 1){
			if(x[i] == x[i - 1]) v.pb(x[i]) , x[i] = x[i - 1] = -1;
		}
		PII val = mp(0 , 0) , ans;
		REP(i , 1 , v.size()){
			int p = (v[i] + v[i - 1]) * 2;
			int s = v[i] * v[i - 1];
			if(solve(val , mp(p * p , s))){
				val = mp(p * p , s);
				ans = mp(v[i] , v[i - 1]);
			}
		}
		cout << ans.A << " " << ans.B << " " << ans.A << " " << ans.B << endl;
	}
    return 0;
}