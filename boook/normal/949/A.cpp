/*input
111
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
#define MAX 200900
#define INF 0x3f3f3f3f

int x[MAX] , ok[MAX];
string s;
int32_t main(){
	IOS;
	string s;
	cin >> s;
	queue<int> f;
	MEM(x , -1);
	REP(i , 0 , s.size()){
		if(s[i] == '0' && ok[i] == 0) f.push(i);
		else {

			if(f.size() == 0) return cout << -1 << endl , 0;
			else x[f.front()] = i , f.pop() , ok[i] = 1;
		}
	}
	stack<int> b;
	RREP(i , s.size() - 1 , 0){
		if(s[i] == '0' && ok[i] == 0) b.push(i);
		else {
			if(b.size() == 0) return cout << -1 << endl , 0;
			else x[i] = b.top() , ok[b.top()] = 1 , ok[b.top()] = 1 , b.pop();
		}
	}
	// REP(i , 0 , s.size()) cout << x[i] << " " ; cout << endl;
	// REP(i , 0 , s.size()) cout << ok[i] << " " ; cout << endl;
	int cnt = 0;
	REP(i , 0 , s.size()) if(ok[i] == 0) cnt ++;
	cout << cnt << endl;
	REP(i , 0 , s.size()) if(ok[i] == 0){
		int now = i;
		vector<int> sol;
		while(now != -1) sol.pb(now) , now = x[now];
		cout << sol.size();
		for(auto to : sol) cout << " " << to + 1;
			cout << endl;
	}
    return 0;
}