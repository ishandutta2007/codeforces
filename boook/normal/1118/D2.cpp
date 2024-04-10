/*input
5 8
2 3 1 1 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200090
#define INF 0x3f3f3f3f

int n , m , x[MAX];
int judge(int now){
	int sum = 0 , pos = 0 , cnt = 0;
	REP(i , 1 , n + 1){
		sum += max(0LL , x[i] - pos);
		cnt ++;
		if(cnt == now) cnt = 0 , pos ++;
	}
	return sum >= m;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n , greater<int>());
	int ans = 0 , ok = 0;
	RREP(i , 25 , 0){
		int to = ans + (1 << i);
		if(judge(to) == 0) ans = to;
		else ok = 1;
	}
	if(ok == 0) cout << -1 << endl;
	else cout << ans + 1 << endl;
    return 0;
}