/*input
7
10 20 3 15 1000 60 16
10
1
2
3
4
5
6
10
20
60
1000
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
#define MAX 100900
#define INF 0x3f3f3f3f

map<int , int> ans;
int n , m , x[MAX];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];

	map<int , int> pre;
	REP(i , 1 , n + 1){
		map<int , int> now;
		pre[0] = 1;
		for(auto to : pre){
			now[__gcd(to.A , x[i])] += to.B;
			ans[__gcd(to.A , x[i])] += to.B;
		}
		pre = now;
	}

	cin >> m;
	REP(i , 1 , m + 1){
		int in;
		cin >> in;
		cout << ans[in] << endl;
	}
    return 0;
}