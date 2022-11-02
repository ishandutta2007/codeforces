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

int m , pos , f[MAX] , z[MAX] , ans[MAX];
string s;
int32_t main(){
	IOS;
	cin >> s >> m >> s;
	f[0] = pos = -1;
	REP(i , 1 , s.size()){
		while(pos != -1 && s[i] != s[pos + 1]) pos = f[pos];
		if(s[i] == s[pos + 1]) pos ++;
		f[i] = pos;
	}
	REP(i , 0 , s.size()) f[i] ++;
	int l = 0 , r = 0;
	REP(i , 0 , s.size()){
		z[i] = max(min(z[i - l] , r - i + 1) , 0);
		while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]]){
			l = i , r = i + z[i] , z[i] ++;
		}
	}
	
	// REP(i , 0 , s.size()) cout << f[i] << " ";cout << endl;
	REP(i , 0 , s.size()){
		int val = (i + 1) / (i + 1 - f[i]);
		if((i + 1) % (i + 1 - f[i]) == 0 && val % m == 0){

			int lim = (i + 1 - f[i]) * (val / m) , tmp = min(z[i + 1] , lim);
			ans[i] ++;
			ans[i + 1 + tmp] --;
		}
	}
	// ababaababaababaababa
	REP(i , 1 , s.size()) ans[i] += ans[i - 1];
	// REP(i , 0 , s.size()) cout << ans[i]; cout << endl;
	REP(i , 0 , s.size()) cout << (ans[i] != 0) ; cout << endl;
	// cout << endl;
    return 0;
}