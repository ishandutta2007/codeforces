/*input
1000000 3
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
	// DBGG("update = " , from);
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int n , m;
int query(int l , int r){
	if(l <= r) return query(r) - query(l - 1);
	// DB4("here" , l , "" , query(l));
	return query(n) - query(l - 1) + query(r);
}
int32_t main(){
	IOS , cin >> n >> m;
	int now = 0 , ans = 1;
	m = min(m , n - m);
	REP(i , 1 , n + 1){
		int to = (now + m) % n;
		int tmp = query((now + 1) % n , (to + n - 1) % n);
		// DB4("query" , (now + 1) % n , (to + n - 1) % n , tmp);
		update(now , 1);
		update(to , 1);
		ans += tmp + 1 , now = to;
		cout << ans << " ";
	}
	cout << endl;
    return 0;
}