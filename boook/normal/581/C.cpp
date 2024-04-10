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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , k;
int x[MAX];
int32_t main(){
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	vector<int> v;
	int cnt = 0 , ans = 0;
	REP(i , 1 , n + 1){
		ans += x[i] / 10;
		if(x[i] % 10 == 0) cnt += (100 - x[i]) / 10;
		else{
			v.pb(10 - (x[i] % 10));
			x[i] += 10 - (x[i] % 10);
			cnt += (100 - x[i]) / 10;
		}
	}
	sort(ALL(v));
	for(auto now : v){
		if(k >= now) ans ++ , k -= now;
	}
	while(cnt > 0 && k >= 10) ans ++ , cnt -- , k -= 10;
	cout << ans << endl;
    return 0;
}