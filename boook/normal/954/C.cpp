/*input
2
1 10
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	set<int> cc;
	REP(i , 2 , n + 1){
		if(x[i] == x[i - 1]) return cout << "NO" << endl , 0;
		if(abs(x[i] - x[i - 1]) == 1) continue;
		else cc.insert(abs(x[i] - x[i - 1]));
	}
	if(cc.size() == 0) cc.insert(1000000000);
	if(cc.size() == 1){
		int ans = *cc.begin() , ok = 1;
		REP(i , 2 , n + 1) if(x[i] - x[i - 1] ==  1 && x[i - 1] % ans == 0) ok = 0;
		REP(i , 2 , n + 1) if(x[i] - x[i - 1] == -1 && x[i - 0] % ans == 0) ok = 0;
		if(ok == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << "1000000000 " << *cc.begin() << endl;
		}
	}
	else cout << "NO" << endl;
    return 0;
}