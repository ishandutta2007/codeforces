/*input
100000
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , b[MAX] = {0 , 5 , 3 , 2 , 6 , 1 , 7 , 4};
int s[MAX * 20] , ls[MAX * 20] , rs[MAX * 20] , pos = 2;
void update(int now , int val , int floor){
	if(floor == -1) s[now] ++;
	else {
		if(val & (1 << floor)){
			if(rs[now] == 0) rs[now] = pos ++;
			update(rs[now] , val , floor - 1);
		}
		else {
			if(ls[now] == 0) ls[now] = pos ++;
			update(ls[now] , val , floor - 1);
		}
		s[now] = s[ls[now]] + s[rs[now]];
	}
}
int query(int now , int val , int floor , int pre){
	if(s[now] == 0) cout << "WA" << endl , exit(0);
	if(floor == -1) return s[now] -- , pre;
	int ans;
	if(val & (1 << floor)) ans = query(ls[now] , val , floor - 1 , pre);
	else {
		if(s[rs[now]]) ans = query(rs[now] , val , floor - 1 , pre ^ (1 << floor));
		else if(s[ls[now]]) ans = query(ls[now] , val , floor - 1 , pre);
		else cout << "WA" << endl , exit(0);
	}
	s[now] = s[ls[now]] + s[rs[now]];
	return ans;	
}
void solve1(){
	if(n % 2 == 1) return cout << "NO" << endl , void();
	cout << "YES" << endl;
	REP(i , 1 , n + 1) update(1 , i , 20);
	RREP(i , n , 1) x[i] = query(1 , i , 20 , 0);
	// REP(i , 1 , n + 1) if(i & x[i]) cout << "WA" << endl;
	REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
}
void solve2(){
	if((1 << __lg(n)) == n || n <= 5) return cout << "NO" << endl , void();
	cout << "YES" << endl;
	if(n == 6) return cout << "5 3 2 6 1 4" << endl , void();
	else {
		int val = n;
		while(val != 7){
			if((1 << __lg(val)) + 2 == val){
				b[val - 0] = val - 2;
				b[val - 2] = val - 1;
				b[val - 1] = val - 0;
				val -= 3;
			}
			else b[val] = val - 1 , b[val - 1] = val , val -= 2;
		}
		// REP(i , 1 , n + 1) if((i & b[i]) == 0){
		// 	cout << i << " " << b[i] << " " << (i & b[i]) << endl;
		// 	return cout << "WA" << endl , void();
		// }
		REP(i , 1 , n + 1) cout << b[i] << " " ; cout << endl;
	}
}
int32_t main(){
	IOS;
	cin >> n;
	solve1();
	solve2();
    return 0;
}