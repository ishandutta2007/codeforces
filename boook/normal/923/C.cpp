/*input
10
331415699 278745619 998190004 423175621 42983144 166555524 843586353 802130100 337889448 685310951
226011312 266003835 342809544 504667531 529814910 684873393 817026985 844010788 993949858 1031395667
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX];
int sum[MAX * 40] , ls[MAX * 40] , rs[MAX * 40] , po = 2;
void update(int now , int floor , int val){
	if(floor == -1) sum[now] ++;
	else {
		if(val & (1 << floor)){
			if(rs[now] == 0) rs[now] = po ++;
			update(rs[now] , floor - 1 , val);
		}
		else {
			if(ls[now] == 0) ls[now] = po ++;
			update(ls[now] , floor - 1 , val);
		}
		sum[now] = sum[ls[now]] + sum[rs[now]];
	}
}
int ans;
void query(int now , int floor , int val){
	if(floor == -1) sum[now] --;
	else {
		if(val & (1 << floor)){
			if(sum[rs[now]]) query(rs[now] , floor - 1 , val);
			else 			 query(ls[now] , floor - 1 , val) , ans += (1 << floor);
		}
		else {
			if(sum[ls[now]]) query(ls[now] , floor - 1 , val);
			else 			 query(rs[now] , floor - 1 , val) , ans += (1 << floor);
		}
		sum[now] = sum[ls[now]] + sum[rs[now]];
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) update(1 , 30 , b[i]);
	REP(i , 1 , n + 1){
		ans = 0;
		query(1 , 30 , a[i]);
		cout << ans << " ";
	}
	cout << endl;
    return 0;
}