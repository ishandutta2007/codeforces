/*input
bwwbwwb
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
#define MAX 300090
#define INF 0x3f3f3f3f

string s;
int x[MAX];
int32_t main(){
	IOS;
	cin >> s;
	int n = s.size();
	s += s;
	s = " " + s;
	REP(i , 2 , s.size()) if(s[i] != s[i - 1]) x[i] ++;
	REP(i , 1 , s.size()) if(x[i]) x[i] += x[i - 1];
	// REP(i , 1 , s.size()) cout << x[i] << " " ; cout << endl;
	multiset<int> cc;
	int pos = 0 , ans = 0;
	REP(i , 1 , s.size()){
		while(pos + 1 <= s.size() && (pos + 1) - i + 1 <= n){
			pos ++;
			cc.insert(x[pos]);
		}
		// DBGG("pos = " , pos);
		if(cc.size()) ans = max(ans , *(prev(cc.end())));
		cc.erase(cc.find(x[i]));
	}
	cout << min(n , ans + 1) << endl;
    return 0;
}