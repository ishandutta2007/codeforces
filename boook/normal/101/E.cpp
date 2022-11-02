/*input
3 3 2
0 1 1
1 1 0
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i <= k ; ++i)
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
// #define int long long
#define MAX 20009
#define INF 0x3f3f3f3f

int n , m , mod , x[MAX] , y[MAX] , ans[MAX + MAX];

long long tma[MAX] , tmb[MAX] , tmc[MAX];
long long *now = tma , *pre = tmb , *tmp = tmc;

inline long long V(int i , int j){
	return (x[i] + y[j]) >= mod ? x[i] + y[j] - mod : x[i] + y[j];
}
void calcUp(int l , int r , int a , int b){
	now[a - 1] = pre[a - 1] = 0;
	REP(i , a , b) now[i] = now[i - 1] + V(l , i);
	REP(i , l + 1 , r){
		swap(pre , now);
		REP(j , a , b){
			now[j] = max(now[j - 1] , pre[j]) + V(i , j);
		}
	}
}
void calcDw(int l , int r , int a , int b){
	now[b + 1] = pre[b + 1] = 0;
	RREP(i , b , a) now[i] = now[i + 1] + V(r , i);
	RREP(i , r - 1 , l){
		swap(pre , now);
		RREP(j , b , a) now[j] = max(now[j + 1] , pre[j]) + V(i , j);
	}
}
void solve(int l , int r , int a , int b , long long val){
	if(l == r) REP(i , l + a , r + b - 1) ans[i] = 1; // right
	else {
		int mid = (l + r >> 1);
		calcUp(l , mid + 0 , a , b) , swap(tmp , now);
		calcDw(mid + 1 , r , a , b);
		REP(i , a , b){
			if(tmp[i] + now[i] == val){
				ans[mid + i] = 2;
				long long frval = tmp[i] , baval = now[i];
				solve(l , mid + 0 , a , i , frval);
				solve(mid + 1 , r , i , b , baval);
				return;
			}
		}
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> mod;
	REP(i , 1 , n) cin >> x[i] , x[i] %= mod;
	REP(i , 1 , m) cin >> y[i] , y[i] %= mod;

	calcUp(1 , n , 1 , m);
	long long all = now[m];
	solve(1 , n , 1 , m , all);
	cout << all << endl;
	REP(i , 2 , n + m - 1){
		if(ans[i] == 1) cout << "S";
		if(ans[i] == 2) cout << "C";
	}cout << endl;
    return 0;
}