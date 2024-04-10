/*input
4 2 0
5 3 1 7
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
#define MAX 400000
#define INF 0x3f3f3f3f

int bit[MAX];
int update(int from , int val){
	for(int i = from + 10 ; i < MAX ; i += i & -i){
		bit[i] += val;
	}
}
int query(int from){
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i){
		cnt += bit[i];
	}
	return cnt;
}
int query(int l , int r){
	return query(r) - query(l - 1);
}
int n , m , k , x[MAX] , l[MAX] , r[MAX];
vector<int> uni;
int32_t main(){
	IOS , cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];

	REP(i , 1 , n + 1){
		if(x[i] % m == 0 && k == 0) x[i] = -1;
		else {
			if(x[i] % m == 0){
				l[i] = x[i] + m * (k - 1);
				r[i] = x[i] + m * k - 1;
			}
			else {
				int id = (x[i] / m + 1) * m;
				if(k == 0){
					l[i] = x[i];
					r[i] = id - 1;
				}
				else {
					l[i] = id + m * (k - 1);
					r[i] = id + m * k - 1;
				}
			}
		}
		r[i] ++;
		// cout << "detail = " ; DB4(i , x[i] , l[i] , r[i]);
	}
	REP(i , 1 , n + 1){
		uni.pb(x[i]);
		uni.pb(l[i]);
		uni.pb(r[i]);
	}
	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1){
		x[i] = lower_bound(ALL(uni) , x[i]) - uni.begin();
		l[i] = lower_bound(ALL(uni) , l[i]) - uni.begin();
		r[i] = lower_bound(ALL(uni) , r[i]) - uni.begin();
	}
	// cout << "0---" << endl;
	// REP(i , 1 , n + 1) {cout << "detail = " ; DB4(i , x[i] , l[i] , r[i]);}
 	int ans = 0;
	REP(i , 1 , n + 1){
		update(l[i] , 1);
		update(r[i] , -1);
	}
	REP(i , 1 , n + 1){
		ans += query(x[i]);
	}
	cout << ans << endl;
    return 0;
}