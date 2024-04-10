/*input
12 1 5 10
3 5 6 7 8 9 5 1 1 1 1 5
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
#define MAX 60000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

typedef vector<vector<int>> V;
V mul(V a , V b){
	V ans(110 , vector<int>(110 , 0));
	REP(i , 0 , 110) REP(j , 0 , 110){
		REP(k , 0 , 110){
			ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	return ans;
}

V ppow(V a , int k){
	if(k == 1) return a;
	if(k % 2 == 0) return ppow(mul(a , a) , k >> 1);
	if(k % 2 == 1) return mul(ppow(mul(a , a) , k >> 1) , a);
}

int n , m , k , mm , x[MAX] , cnt[MAX];
int32_t main(){
	cin >> n >> m >> k >> mm;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cnt[x[i] % mm] ++;

	V a(110 , vector<int>(110 , 0));
	REP(i , 0 , mm){
		REP(j , 1 , n + 1){
			int to = (i * 10 + x[j]) % mm;
			a[to][i] ++;
			// DB4(i , x[j] , i * 10 + x[j] , to);
		}
	}
	// REP(i , 0 , mm){
	// 	REP(j , 0 , mm){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	if(m == 1) cout << cnt[k]  << endl;
	else {
		a = ppow(a , m - 1);
		int ans = 0;
		REP(i , 0 , mm) ans = (ans + a[k][i] * cnt[i]) % mod;
		cout << ans << endl;
	}
    return 0;
}