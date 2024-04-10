/*input
11 6 100
12 5
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
#define MAX 
#define INF 0x3f3f3f3f

int h1 , a1 , c1;
int h2 , a2;

int32_t main(){
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	vector<int> sol;
	while(h2 > 0){
		if(h2 - a1 > 0){
			if(h1 - a2 <= 0){
				sol.pb(0);
				h1 += c1;
				h1 -= a2;
			}
			else {
				h2 -= a1;
				h1 -= a2;
				sol.pb(1); 
			}
		}
		else {
			h2 -= a1;
			sol.pb(1);
		}
	}
	cout << sol.size() << endl;
	for(auto to : sol){
		if(to == 0) cout << "HEAL" << endl;
		else cout << "STRIKE" << endl;
	}
    return 0;
}