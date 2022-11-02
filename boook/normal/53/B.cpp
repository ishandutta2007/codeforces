/*input
2 1
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
#define int long long
#define INF 0x3f3f3f3f

int a , b;
PII ans = mp(0 , 0);
void update(int a,  int b){
	if(a * b > ans.A * ans.B) ans = mp(a , b);
	else ans = max(ans , mp(a , b));
}
int32_t main(){
	IOS;
	cin >> a >> b;
	// 0.8 <= a / b <= 1.25
	REP(i , 0 , 32){
		int bb = (1LL << i);
		int l = bb * 4 / 5 + (bb % 5 != 0);
		int r = bb * 5 / 4;
		if(l <= r && bb <= b && l <= a){
			int aa = min(r , a);
			update(aa , bb);
		}
	}
	REP(i , 0 , 32){
		int aa = (1LL << i);
		int r = aa * 5 / 4;
		int l = aa * 4 / 5 + (aa % 5 != 0);
		if(l <= r && aa <= a && l <= b){
			int bb = min(r , b);
			update(aa , bb);
		}
	}
	cout << ans.A << " " << ans.B << endl;
    return 0;
}