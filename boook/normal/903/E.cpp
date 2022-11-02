/*input
5 4
abcd
dcba
acbd
dbca
zzzz
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , m , ok[MAX] , dis[MAX];
set<string> cc;
int solve(string s){
	sort(ALL(s));
	cc.insert(s);
	if(cc.size() > 1){
		cout << -1 << endl;
		exit(0);
	}
	REP(i , 1 , s.size()) if(s[i] == s[i - 1]) return 1;
	return 0;
}
string s[MAX];
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];

	REP(i , 0 , n) ok[i] = solve(s[i]);

	REP(i , 1 , n){
		REP(j , 0 , m){
			if(s[0][j] != s[i][j]) dis[i] ++;
		}
	}

	REP(ii , 0 , m) REP(jj , ii + 1 , m){
		int pass = 1;
		REP(j , 1 , n){
			int res = dis[j];
			if(s[0][ii] != s[j][ii]) res --;
			if(s[0][jj] != s[j][jj]) res --;
			if(s[0][ii] != s[j][jj]) res ++;
			if(s[0][jj] != s[j][ii]) res ++;
			if(res != 0 && res != 2) pass = 0;
			if(res == 0 && ok[j] == 0) pass = 0;
		}
		if(pass){
			swap(s[0][ii] , s[0][jj]);
			return cout << s[0] << endl , 0;
		}
	}
	cout << -1 << endl;
    return 0;
}