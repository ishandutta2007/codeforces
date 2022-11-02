/*input
RGBB
BRRBRR
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
#define int long long
#define MAX 1000090
#define INF 0x3f3f3f3f

int l[MAX] , r[MAX] , no[MAX][9] , pos;
string s , p;
int32_t main(){
	IOS;
	cin >> s >> p , s = " " + s , p = " " + p;
	REP(i , 1 , p.size()){
		if(i != 1){
			int a = p[i - 1] == 'R' ? 0 : p[i - 1] == 'G' ? 1 : 2;
			int b = p[i - 0] == 'R' ? 0 : p[i - 0] == 'G' ? 1 : 2;
			no[i][a * 3 + b] = 1;
		}
	}
	REP(i , 1 , p.size()) REP(j , 0 , 9) no[i][j] += no[i - 1][j];
	pos = 1;
	REP(i , 1 , s.size()){
		while(pos < p.size() && p[pos] != s[i]) pos ++;
		r[i] = min((int)p.size() - 1 , pos) , pos ++;
	}
	pos = 1 , l[0] = 1;
	REP(i , 1 , p.size()){
		while(pos < s.size() && s[pos] != p[i]) pos ++;
		l[pos + 1] = i + 1;
		if(pos < s.size()) pos ++;
	}
	// REP(i , 1 , s.size()) cout << l[i] << " " ; cout << endl;
	REP(i , 1 , s.size()) l[i] = max(l[i] , l[i - 1]);

	// REP(i , 1 , s.size()) cout << l[i] << " " ; cout << endl;
	// REP(i , 1 , s.size()) cout << r[i] << " " ; cout << endl;

	int ans = 0;
	REP(i , 1 , s.size()){
		ans += r[i] - l[i] + 1;
		if(i != 1 && s[i - 1] != s[i]){
			int a = s[i - 0] == 'R' ? 0 : s[i - 0] == 'G' ? 1 : 2;
			int b = s[i - 1] == 'R' ? 0 : s[i - 1] == 'G' ? 1 : 2;
			ans -= no[r[i]][a * 3 + b] - no[l[i] - 1][a * 3 + b];
		}
		// DBGG(i , ans);
	}
	cout << ans <<  endl;
    return 0;
}