/*input
1 999
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
#define MAX 100000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod; 
}
int n , m;

int32_t main(){
	int ans = 0;
	cin >> n >> m;
	if(m % n != 0 || m < n){
		cout << 0 << endl;
	}
	else {
		m /= n;
		if(m == 1){
			cout << 1 << endl;
		}
		else {
			int tmp = m;
			set<int> cc;
			REP(i , 2 , MAX){
				if(i * i > tmp) break;
				else if(tmp % i == 0){
					while(tmp % i == 0) tmp /= i;
					cc.insert(i);
				}
			}
			if(tmp != 1) cc.insert(tmp);
			vector<int> v;
			for(auto to : cc) v.pb(to);

			// for(auto to : cc) cout <<to << " " ;cout << endl;
			int ans = 0 , nn = cc.size();
		// DBGG("nn = " , nn);

			REP(i , 0 , (1 << nn)){
				int pat = i , u = 1 , vv = 1;
				REP(j , 0 , v.size()){
					if(pat % 2){
						u = -u;
						vv *= v[j];
					}
					pat >>= 1;
				}
				// DB4(vv , u , "get = " , u * ppow(2 , m / vv - 1));
				ans = (ans + u * ppow(2 , m / vv - 1)) % mod;
				ans = (ans % mod + mod) % mod;
			}
			cout << ans << endl;
		}
	}
    return 0;
}