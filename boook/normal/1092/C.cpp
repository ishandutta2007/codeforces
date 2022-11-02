/*input
2
a
c
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
#define MAX 220
#define INF 0x3f3f3f3f

int n , ans[MAX];
string s[MAX];
vector<int> sol[MAX];
int PRE(string a , string b){
	return a.substr(0 , b.size()) == b;
}
int SUF(string a , string b){
	string tmp = a.substr(a.size() - b.size() , b.size());
	assert(tmp.size() == b.size());
	return tmp == b;
}
int solve(){
	string pre = s[sol[n - 1][0]];
	string suf = s[sol[n - 1][1]];
	ans[sol[n - 1][0]] = 0;
	ans[sol[n - 1][1]] = 1;
	REP(i , 1 , n - 1){
		if(PRE(pre , s[sol[i][0]]) && SUF(suf , s[sol[i][1]])){
			ans[sol[i][0]] = 0;
			ans[sol[i][1]] = 1;
		}
		else if(PRE(pre , s[sol[i][1]]) && SUF(suf , s[sol[i][0]])){
			ans[sol[i][0]] = 1;
			ans[sol[i][1]] = 0;
		}
		else return 0;
	}
	return 1;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + n - 2 + 1) cin >> s[i];
	REP(i , 1 , n + n - 2 + 1) sol[s[i].size()].pb(i);
	if(solve() == 0){
		swap(sol[n - 1][0] , sol[n - 1][1]);
		solve();
	}
	REP(i , 1 , n + n - 2 + 1) cout << (ans[i] == 0 ? "P" : "S"); cout << endl;
    return 0;
}