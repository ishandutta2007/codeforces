/*input
7 26
0 15 12 9 13 0 14
11 1 0 13 15 12 0
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
#define MAX 100090
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m;
int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int a[MAX] , b[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	int all = 1 , ans = 0;
	REP(i , 1 , n + 1){
		if(a[i] != 0 && b[i] != 0){
			if(a[i] > b[i]) ans = (ans + all) % mod;
			if(a[i] != b[i]) break;
		}
		else if(a[i] == 0 && b[i] == 0){
			int las = all * ppow(m , mod - 2) % mod;
			int val = (all + mod - las) % mod * ppow(2 , mod - 2) % mod;
			ans = (ans + val) % mod;
			all = las;
		}
		else {
			int val = all * ppow(m , mod - 2) % mod , good;
			if(a[i] == 0) good = m - b[i];
			if(b[i] == 0) good = a[i] - 1;
			ans = (ans + val * good) % mod;
			all = val;
		}
	}
	cout << ans << endl;
    return 0;
}