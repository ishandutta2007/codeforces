/*input
1 [[][]][]
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 1000
#define INF 0x3f3f3f3f

string s;
vector<string> ans;
int dp[MAX][MAX] , r[MAX] , l[MAX];
int DP(int a , int b){
	if(dp[a][b] || a > b) return dp[a][b];
	if(r[a] == b) return dp[a][b] = DP(a + 1 , b - 1) + 1;
	else return dp[a][b] = max(DP(a , r[a]) , DP(r[a] + 1 , b));
}
int len;
void solve(int a , int b , int cnt , int lok , int rok){
	// DB4(a , b , cnt , lok);
	string aa; aa.resize(1 + len * 2 , ' ');
	string bb; bb.resize(1 + len * 2 , ' ');

	aa[cnt] = aa[aa.size() - cnt - 1] = '+';
	REP(i , cnt + 1 , aa.size() - cnt - 1) aa[i] = '|';
	bb[cnt] = bb[bb.size() - cnt - 1] = '+';
	REP(i , cnt + 1 , bb.size() - cnt - 1) bb[i] = '|';
	if(lok) aa[cnt - 1] = aa[aa.size() - cnt] = '-';
	if(rok) bb[cnt - 1] = bb[bb.size() - cnt] = '-';
	// DB4("aa = " , aa , "bb = " , bb);
	if(r[a] == b){
		if(DP(a , b) == 1){
			string tmp , xxx; tmp.resize(1 + len * 2 , ' ');
			xxx = tmp;
			tmp[cnt] = tmp[tmp.size() - cnt - 1] = '-';
			// DBGG("tmp = " , tmp);
			ans.pb(aa) , ans.pb(tmp) , ans.pb(xxx) , ans.pb(tmp) , ans.pb(bb);
		}
		else {
			ans.pb(aa);
			solve(a + 1 , b - 1 , cnt + 1 , 1 , 1);
			ans.pb(bb);
		}
	}
	else {
		solve(a , r[a] , cnt , lok , 0);
		solve(r[a] + 1 , b , cnt , 0 , rok);
	}
}
int32_t main(){
	IOS , cin >> s >> s;
	stack<int> cc;
	REP(i , 0 , s.size()){
		if(s[i] == '[') cc.push(i);
		else {
			l[i] = cc.top();
			r[cc.top()] = i;
			cc.pop();
		}
	}
	len = DP(0 , s.size() - 1);
	// DBGG("len = " , len);
	solve(0 , s.size() - 1 , 0 , 0 , 0);
	REP(i , 0 , 1 + len * 2){
		REP(j , 0 , ans.size()){
			cout << ans[j][i];
		}
		cout << endl;
	}
    return 0;
}