/*input
19
3
4
2
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
#define INF 0x3f3f3f3f

int n , k , a , b , ans;
int32_t main(){
	IOS;
	cin >> n >> k >> a >> b;
	int ans = 0;
	if(k == 1){
		cout << (n - 1) * a << endl;
	}
	else {
		while(n != 1){
			while(n % k == 0){
				int to = n / k;
				int v1 = (n - to) * a;
				int v2 = b;
				ans += min(v1 , v2);
				n = to;
			}
			if(n != 1) {
				if(n <= k) ans += (n - 1) * a , n = 1;
				else {
					int tmp = n / k * k;
					ans += (n - tmp) * a;
					n = tmp;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}