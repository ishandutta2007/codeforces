/*input
2
10 10
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX] , sol[MAX];
set<int> cc;
int cmp(int a , int b){
	return x[a] > x[b];
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n , cmp);
	int cnt = n % 2;
	cc.insert(0);
	cc.insert(n + 1);
	REP(i , 1 , n + 1){
		int now = sol[i];
		cc.insert(now);
		auto tmp = cc.find(now);
		int v1 = *prev(tmp) , v2 = *next(tmp);
		cnt -= (v2 - v1 - 1) % 2;
		cnt += (now - v1 - 1) % 2;
		cnt += (v2 - now - 1) % 2;
		if(i == n || x[sol[i]] != x[sol[i + 1]]){
			if(cnt != 0) return cout << "NO" << endl , 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}