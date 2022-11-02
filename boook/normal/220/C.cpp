/*input
4
2 1 3 4
3 4 2 1
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , att[MAX] , btt[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) cin >> a[i];
	REP(i , 0 , n) cin >> b[i];
	REP(i , 0 , n) att[a[i]] = i;
	REP(i , 0 , n) btt[b[i]] = i;
	multiset<int> cc;
	REP(i , 0 , n) cc.insert(i - att[b[i]]);
	REP(i , 0 , n){
		int ans = INF;
		auto tmp = cc.lower_bound(i);
		if(tmp != cc.end()) 
			ans = min(ans , (*tmp) - i);
		if(tmp != cc.begin())
			ans = min(ans , i - (*prev(tmp)));
		cc.erase(cc.find(i - att[b[i]]));
		cc.insert(i - att[b[i]] + n);
		cout << ans << endl;
	}
    return 0;
}