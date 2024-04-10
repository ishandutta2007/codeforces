/*input
3 5
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define pb push_back
#define int long long
#define mp make_pair
int n , m;
int solve(int now){
	// DBGG("now" , now);
	REP(i , 2 , now) if(now % i == 0){
		return 0;
	}
	return 1;
}
int32_t main(){
	cin >> n >> m;
	int ok = 1;
	if(solve(n) == 0) ok = 0; 
	if(solve(m) == 0) ok = 0; 
	REP(i , n + 1 , m) if(solve(i)) ok = 0;
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}