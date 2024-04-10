/*input
5 2 1 2 2 1
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) x[i] %= 2;
	REP(i , 2 , n + 1) if(x[i] && x[i - 1]) x[i - 1] = x[i] = 0;
	vector<int> v;
	REP(i , 1 , n + 1) if(x[i]){
		if(v.size() && (i - v.back()) % 2 == 1) v.pop_back();
		else v.pb(i);
	}
	if(v.size() == 1){
		if((n + 1 - v.back()) % 2 == 1 && (v.back() - 0) % 2 == 1) v.pop_back();
	}
	if(v.size()) cout << "NO" << endl;
	else cout << "YES" << endl;
    return 0;
}