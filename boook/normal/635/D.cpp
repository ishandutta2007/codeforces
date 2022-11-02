/*input
5 4 10 1 6
1 1 5
1 5 5
1 3 2
1 5 2
2 1
2 2
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
#define INF 0x3f3f3f3f

void update(int from , int val , int bit[MAX]){
	for(int i = from ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from , int bit[MAX]){
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i){
		cnt += bit[i];
	}
	return cnt;
}


int x1[MAX] , x2[MAX] , bit1[MAX] , bit2[MAX];
int n , m , a , b , k;

int32_t main(){
	IOS;
	cin >> n >> m >> a >> b >> k;
	REP(i , 1 , k + 1){
		int ty , q , w , tmp;
		cin >> ty;
		if(ty == 1){
			cin >> q >> w;
			tmp = min(w , b - x1[q]) , x1[q] += tmp;
			update(q , tmp , bit1);
			tmp = min(w , a - x2[q]) , x2[q] += tmp;
			update(q , tmp , bit2);
		}
		else {
			// REP(i , 1 , n + 1) cout << x1[i] << " "; cout << endl;
			// REP(i , 1 , n + 1) cout << x2[i] << " "; cout << endl;
			cin >> q;
			int l = q , r = min(n , q + m - 1);
			cout << query(l - 1 , bit1) + query(n , bit2) - query(r , bit2) << endl;
		}
	}
    return 0;
}