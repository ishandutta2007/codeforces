/*input
3 38
5 2 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 2e5 + 900;
const int INF = 0x3f3f3f3f;

int n , m , x[MAX];
PII bit[MAX];
PII operator + (PII a , PII b){ return mp(a.F + b.F , a.S + b.S); }
PII operator - (PII a , PII b){ return mp(a.F - b.F , a.S - b.S); }

void update(int from , PII val){
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] = bit[i] + val;
}
PII query(int from){
	PII cnt = mp(0 , 0);
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt = cnt + bit[i];
	return cnt;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	int ans = 0 , sum = 0 , cnt = 0;
	REP(i , 1 , n + 1) sum += x[i] , cnt += 1 , update(i , mp(x[i] , 1));

	while(sum > 0 && m > 0){
		// cout << m << endl;
		// cout << m / sum << endl;
		if(m >= sum) ans += cnt * (m / sum) , m %= sum;
		else if(cnt == 1) break;
		else {
			int now = 1;
			while(now <= n){
				PII str = query(now - 1);
				PII suf = query(n) - str;
				if(suf.F <= m){
					ans += suf.S , m -= suf.F;
					break;
				}

				int pos = n + 1;
				PII del;
				RREP(j , 20 , 0){
					int to = pos - (1 << j);
					if(to >= now){
						PII tmp = query(to) - str;
						if(m < tmp.F) pos = to , del = tmp;
					}
				}
				// DBGG("pre m = " , m);
				// DB4("del = " , pos , del.F , del.S);
				cnt -- , sum -= x[pos];
				// DBGG("???" , del.F - x[pos]);
				m -= del.F - x[pos];
				ans += del.S - 1;
				
				update(pos , mp(-x[pos] , -1));
				now = pos + 1;
				// DBGG("now ans = " , ans);
				// cout << endl;
			}
		}
		// DB4("ans =------------------------- " , ans , "m = " , m);
	}
	cout << ans << endl;
    return 0;
}