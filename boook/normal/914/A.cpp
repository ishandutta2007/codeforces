/*input
8
1 2 4 8 16 32 64 576
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

int n , ans = -INF;
int32_t main(){
	IOS;
	set<int> cc;	
	REP(i , 0 , 100000){
		cc.insert(i * i);
	}
	cin >> n;
	REP(i , 1 , n + 1){
		int in;
		cin >> in;
		if(cc.find(in) == cc.end()){
			ans = max(ans , in);
		}
	}
	cout << ans << endl;
    return 0;
}