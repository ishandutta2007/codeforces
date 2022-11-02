/*input
5
2 1 2 4 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 200900;
const int INF = 0x3f3f3f3f;

int n , x[MAX];

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int sum = 0;
	map<int , int> cc;
	REP(i , 1 , n + 1) cc[x[i]] ++ , sum += x[i];
	vector<int> ans;
	REP(i , 1 , n + 1){
		int las = sum - x[i];
		if(las % 2 == 0){
			int goal = las / 2;
			cc[x[i]] --;
			if(cc[goal] != 0){
				ans.pb(i);
			}
			cc[x[i]] ++;
		}
	}
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}