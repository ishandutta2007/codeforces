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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , z[MAX] , ok[MAX];
string s;
int32_t main(){
	IOS;
	cin >> s , n = s.size();
	int l = 0 , r = 0;
	REP(i , 0 , n){
		z[i] = max(min(z[i - l] , r - i + 1) , 0);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
			l = i , r = i + z[i] , z[i] ++;
		}
	}
	REP(i , 1 , n){
		if(i + z[i] == s.size()) ok[z[i] - 1] = 1;
		else ok[z[i]] = 1;
	}
	RREP(i , n , 1) ok[i] = max(ok[i + 1] , ok[i]);

	// REP(i , 0 , n) cout << z[i] << " "; cout << endl;
	// REP(i , 0 , n) cout << ok[i] << " "; cout << endl;
	int ans = -1;
	REP(i , 1 , n + 1) if(z[n - i] == i && ok[i]) ans = i;
	if(ans == -1) cout << "Just a legend" << endl;
	else{
		REP(i , 0 , ans) cout << s[i] ; cout << endl;
	}
    return 0;
}