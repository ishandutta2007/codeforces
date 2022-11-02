/*input
10
121 56 78 81 45 100 1 0 54 78
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
#define MAX 200900
#define INF 1000000000000LL

int n , x[MAX];
vector<int> yes , no;
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		int tmp = sqrt(x[i]);
		if(tmp * tmp == x[i]){
			if(x[i] <= 1) no.pb(2 - x[i]);
			else no.pb(1);
		}
		else {
			int l = max(0LL , tmp - 3);
			int r = tmp + 3 , ans = INF;
			REP(j , l , r + 1) ans = min(ans , abs(j * j - x[i]));
			yes.pb(ans);
		}
	}
	// DBGG(yes.size() , no.size());
	if(yes.size() == n / 2) cout << 0 << endl;
	else if(yes.size() > n / 2){
		sort(ALL(yes));
		int ans = 0;
		REP(i , 0 , (int)(yes.size()) - n / 2)
			ans += yes[i];
		cout << ans << endl;
	}
	else {
		sort(ALL(no));
		int ans = 0;
		REP(i , 0 , (int)(no.size()) - n / 2)
			ans += no[i];
		cout << ans << endl;	
	}
    return 0;
}