/*input
5 1 1
1 0 0 0 4
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , a[MAX] , t[MAX];
int judge(int now){
	int l = 1 + now , r = n - now;
	if(l > r) return 1;
	else {
		int pos = l , have = 0;
		REP(i , 1 , n + 1) x[i] = a[i];
		REP(i , 1 , n + 1){
			if(pos > r) return 1;
			// DB4("now solve i = " , i , "pos = " , pos);
			while(x[i]){
				int dis = abs(pos - i) , tt = (dis % m == 0) ? dis / m : dis / m + 1;
				// DB4("tt = " , tt , "dis = " , dis);
				if(tt <= t[pos]){
					int las = min(k - have , x[i]);
					x[i] -= las , have += las;
					// DB4("have = " , have , "pos = " , pos);
					if(have == k) have = 0 , pos ++;
				}
				else break;
			}
		}
		if(pos > r) return 1;
		else return 0;
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) t[i] = min(i , n + 1 - i);
	// REP(i , 1 , n + 1) cout << t[i] << " " ;  cout << endl;
	// cout << judge(0) << endl;
	// cout << judge(1) << endl;
	// cout << judge(2) << endl;
	// cout << judge(3) << endl;
	int ans = (n + 1) / 2;
	RREP(i , 20 , 0){
		int to = ans - (1 << i);
		if(to >= 0 && judge(to)) ans = to;
	}
	cout << ans << endl;
    return 0;
}