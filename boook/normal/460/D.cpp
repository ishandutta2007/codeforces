/*input

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
#define int int_fast64_t
#define MAX 
#define INF 10000000000000000LL

int l , r , k , ans = INF;
vector<int> v;
void DFS(vector<int> now , int floor , int val){
	if(now.size() > k) return;
	if(floor == r + 1){
		if(ans > val && now.size()) ans = val , v = now;
	}
	else {
		DFS(now , floor + 1 , val);
		now.pb(floor);
		DFS(now , floor + 1 , val ^ floor);
	}
}
int32_t main(){
	IOS;
	cin >> l >> r >> k;
	if(r - l + 1 >= 5 && k >= 4){
		cout << 0 << endl;
		cout << 4 << endl;
		REP(i , 0 , 4) cout << (l % 2 + i + l) << " "; cout << endl;
		return 0;
	}
	if(r - l + 1 < 5){
		DFS(vector<int>() , l , 0);
		cout << ans << endl;
		cout << v.size() << endl;
		for(auto to : v) cout << to << " " ; cout << endl;
		return 0;
	}
	if(k == 1){
		cout << l << endl;
		cout << 1 << endl;
		cout << l << endl;
		return 0;
	}
	if(k == 2){
		cout << 1 << endl;
		cout << 2 << endl;
		REP(i , 0 , 2) cout << (l % 2 + i + l) << " "; cout << endl;
		return 0;
	}
	if(k == 3){
		int sml = 1 , big = 3;
		REP(i , 0 , 50){
			if(l <= sml && sml <= r && l <= big && big <= r){
				cout << 0 << endl;
				cout << 3 << endl;
				cout << sml << " " << (sml ^ big) << " " << big << endl;
				return 0;
			}
			else {
				sml = (sml << 1 | 1);
				big = (big << 1);
			}
		}
		if(l == 1){
			cout << 0 << endl;
			cout << 3 << endl;
			cout << "1 2 3" << endl;
		}
		else {	
			cout << 1 << endl;
			cout << 2 << endl;
			REP(i , 0 , 2) cout << (l % 2 + i + l) << " "; cout << endl;
		}
		return 0;
	}
    return 0;
}