/*input

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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int int_fast64_t
#define MAX 300900
#define INF 0x3f3f3f3f

struct N{int a , b , h;} x[MAX];
int cmp(N a , N b){
	if(a.b != b.b) return a.b > b.b;
	if(a.b == b.b) return a.a > b.a;
}

int bit[MAX];
void update(int from , int val){
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] = max(bit[i] , val);
}
int query(int from){
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt = max(cnt , bit[i]);
	return cnt;
}
vector<int> uni;
int n;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) cin >> x[i].a >> x[i].b >> x[i].h;

	REP(i , 0 , n) uni.pb(x[i].a) , uni.pb(x[i].b);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 0 , n) x[i].a = lower_bound(ALL(uni) , x[i].a) - uni.begin() + 1;
	REP(i , 0 , n) x[i].b = lower_bound(ALL(uni) , x[i].b) - uni.begin() + 1;

	sort(x , x + n , cmp);
	int ans = 0;
	REP(i , 0 , n){
		int tmp = query(x[i].b - 1) + x[i].h;
		update(x[i].a , tmp) , ans = max(ans , tmp);
	}
	cout << ans << endl;
    return 0;
}