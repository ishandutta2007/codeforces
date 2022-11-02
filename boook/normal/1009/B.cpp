/*input
21110
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

int u[MAX];
string s;
int32_t main(){
	IOS;
	cin >> s;
	string ans;
	int ok = 0;
	REP(i , 0 , s.size()) if(u[i] == 0){
		u[i] = 1;
		if(s[i] == '2' && ok == 0){
			ok = 1;
			REP(j , i + 1 , s.size()) if(s[j] == '1') ans += "1" , u[j] = 1;
			ans += s[i];
		}
		else ans += s[i];
	}
	// cout << ans << endl;
	vector<int> sol;
	sol.pb(-1);
	REP(i , 0 , ans.size()) if(ans[i] == '2') sol.pb(i);
	sol.pb(ans.size());
	REP(i , 1 , sol.size()){
		int ql = sol[i - 1] + 1 , qr = sol[i] - 1;
		if(ql <= qr){
			sort(ans.begin() + ql , ans.begin() + qr + 1);
		}
	}
	cout << ans << endl;
    return 0;
}