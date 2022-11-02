/*input
5
2 2 3 4 5
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

int n , x[MAX] , sum = 0;
multiset<int> cc;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) sum += x[i];
	if(sum % 2 == 0) sum /= 2;
	else return cout << "NO" << endl , 0;

	REP(i , 2 , n + 1) cc.insert(x[i]);
	REP(i , 1 , n + 1) if(x[i] == sum) return cout << "YES" << endl , 0;
	int now = 0;
	REP(i , 1 , n + 0){
		now += x[i];
		if(cc.find(sum - now) != cc.end()) return cout << "YES" << endl , 0;
		else cc.erase(cc.find(x[i + 1]));
	}
	RREP(i , n - 1 , 1) cc.insert(x[i]);
	now = 0;
	RREP(i , n - 0 , 2){
		now += x[i];
		if(cc.find(sum - now) != cc.end()) return cout << "YES" << endl , 0;
		else cc.erase(cc.find(x[i - 1]));
	}
	cout << "NO" << endl;
    return 0;
}