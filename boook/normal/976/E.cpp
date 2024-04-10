#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , k , h[MAX] , d[MAX] , sol[MAX] , v[MAX];
int cmp(int a , int b){ return h[a] - d[a] > h[b] - d[b]; }
int solve(){
	int base = 0;
	REP(i , 1 , n + 1) base += d[i];

	REP(i , 1 , n + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n , cmp);

	int val = 0 , ans = base , las = 0;
	REP(i , 1 , k + 1) v[i] = max(0LL , h[sol[i]] - d[sol[i]]);
	REP(i , 1 , k + 1) val += v[i];
	REP(i , 1 , k + 0) las += v[i];
	REP(i , 1 , k + 1) ans = max(ans , base + val - v[i] + ((h[sol[i]] << m) - d[sol[i]]));
	REP(i , k + 1 , n + 1) ans = max(ans , base + las + ((h[sol[i]] << m) - d[sol[i]]));
	return ans;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k , k = min(k , n);
    REP(i , 1 , n + 1) cin >> h[i] >> d[i];
    int base = 0;
    REP(i , 1 , n + 1) base += d[i];
    if(k == 0) return cout << base << endl , 0;
    cout << solve() << endl;
    return 0;
}