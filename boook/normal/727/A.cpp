/*input
100 40021
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
#define MAX 
#define INF 0x3f3f3f3f

int a , b;
stack<int> cc;
int DFS(int now){
	if(now > b) return 0;
	if(now == b){
		cc.push(now);
		return 1;
	}
	else {
		if(DFS(now * 2)){
			cc.push(now);
			return 1;
		}
		if(DFS(now * 10 + 1)){
			cc.push(now);
			return 1;
		}
		return 0;
	}
}
int32_t main(){
	IOS;
	cin >> a >> b;
	if(DFS(a)){
		cout << "YES" << endl;
		cout << cc.size() << endl;
		while(cc.size()) cout << cc.top() << " " , cc.pop(); cout << endl;

	}
	else {
		cout << "NO" << endl;

	}
    return 0;
}