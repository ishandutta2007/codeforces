/*input
4
insert 1
insert 1
removeMin
getMin 2
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
#define MAX 
#define INF 0x3f3f3f3f

vector<pair<string , int>> ans;
int n , val;
string s;
int32_t main(){
	IOS;
	cin >> n;
	priority_queue<int , vector<int> , greater<int>> pq;
	REP(i , 1 , n + 1){
		cin >> s;
		if(s == "insert"){
			cin >> val;
			ans.pb(s , val);
			pq.push(val);
		}
		if(s == "removeMin"){
			if(pq.size() == 0){
				ans.pb("insert" , 0);
				pq.push(0);
			}
			ans.pb(mp(s , 0));
			pq.pop();
		}
		if(s == "getMin"){
			cin >> val;
			while(pq.size() && pq.top() < val){
				ans.pb("removeMin" , 0);
				pq.pop();
			}
			if(pq.size() == 0 || pq.top() > val){
				pq.push(val);
				ans.pb("insert" , val);
			}
			ans.pb("getMin" , val);
		}
	}
	cout << ans.size() << endl;
	for(auto to : ans){
		if(to.A == "removeMin") cout << to.A << endl;
		else cout << to.A << " " << to.B << endl;
	}
    return 0;
}