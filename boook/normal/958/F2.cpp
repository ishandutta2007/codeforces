/*input
8 3
3 3 1 2 2 1 1 3
3 1 1
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX] , cnt[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , m + 1) cin >> b[i];

	int pos = 1 , ans = INF , sum = 0;
	set<int> ok;
	REP(i , 1 , m + 1) sum += b[i];
	REP(i , 1 , m + 1) if(b[i] == cnt[i]) ok.insert(i);

	while(ok.size() != m && pos <= n){
		cnt[a[pos]] ++;
		if(cnt[a[pos]] >= b[a[pos]]) ok.insert(a[pos]);
		pos ++;
	}
	if(ok.size() == m) ans = min(ans , pos - 1 - sum);

	REP(i , 2 , n + 1){
		int val = a[i - 1];
		cnt[val] --;
		if(cnt[val] < b[val]) ok.erase(val);

		while(ok.size() != m && pos <= n){
			cnt[a[pos]] ++;
			if(cnt[a[pos]] >= b[a[pos]]) ok.insert(a[pos]);
			pos ++;
		}
		if(ok.size() == m) ans = min(ans , pos - i - sum);
	}
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}