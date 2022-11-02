/*input
3
2 2 2
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX];
int solve(int to){
	map<int , int> cc;
	REP(i , to + 1 , n + 1) cc[x[i]] ++;
	REP(i , 1 , to + 1){
		int j = n + 1 - i;
		if(j <= to && x[i] != x[j]) return 0;
		if(j <= to);
		else{
			if(cc.find(x[i]) == cc.end()) return 0;
			else cc[x[i]] --;
		}
	}
	int cnt = 0;
	for(auto to : cc){
		if(to.B < 0) return 0;
		else if(to.B % 2 == 1) cnt ++;
	}
	return cnt <= 1;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int good = 1;
	REP(i , 1 , n + 1) if(x[i] != x[n + 1 - i]) good = 0;
	if(good) cout << n * (n + 1) / 2 << endl;
	else {
		int l = 0 , r = 0;
		RREP(j , 20 , 0){
			int to = l + (1 << j);
			if(to <= n && solve(to)) l = to;
		}
		reverse(x + 1 , x + 1 + n);
		RREP(j , 20 , 0){
			int to = r + (1 << j);
			if(to <= n && solve(to)) r = to;
		}
		reverse(x + 1 , x + 1 + n);
		
		int sml = 0;
		REP(i , 1 , n + 1){
			if(x[i] != x[n + 1 - i]){
				sml = i;
				break;
			}
		}
		if(l == 0 && r == 0) cout << 0 << endl;
		else {
			int ans = (l + 1) * (r + 1) - (l + 1 - sml) * (r + 1 - sml);
			cout << ans << endl;
		}
	}
    return 0;
}