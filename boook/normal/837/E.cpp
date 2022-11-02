#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
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
#define INF 1000000000000000LL

int a , b , ans = 0;
vector<int> v;
int32_t main(){
	cin >> a >> b;
	int p = __gcd(a , b);
	a /= p , b /= p;

	int tmp = a;
	REP(i , 2 , INF){
		if(i * i > tmp) break;
		if(tmp % i == 0){
			while(tmp % i == 0){
				v.pb(i) , tmp /= i;
			}
		}
	}
	if(tmp != 1) v.pb(tmp);

	// for(auto to : v) cout << to << " " ; cout << endl;

	while(1){
		if(b == 0) break;
		else if(a == 1) { ans += b; break; }
		else {
			int xx = -INF;
			REP(i , 0 , v.size()){
				if(v[i] == -1) continue;
				else xx = max(xx , b / v[i] * v[i]);
			}
			if(xx == -INF){ ans += b; break; }

			ans += b - xx , b = xx;
			// DB4("ans = " , ans , a , b);
			p = __gcd(a , b) , a /= p , b /= p;
			REP(i , 0 , v.size()){
				if(v[i] == -1) continue;
				else if(p == 1) continue;
				else if(p % v[i] == 0) p /= v[i] , v[i] = -1;
			}
		}
	}
	cout << ans << endl;
    return 0;
}