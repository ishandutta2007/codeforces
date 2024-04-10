#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define BC 37
int AC;

string s;
int h[MAX][2] , v[MAX][2] , v2[MAX][2];
int query(int x , int y , int ty , int re){
	if(re == 0){
		x ++ , y ++;
		int len = y - x + 1;
		int tmp = v[x - 1][ty] * h[len][ty] % mod;
		tmp = v[y][ty] - tmp;
		tmp = (tmp % mod + mod) % mod;
		return tmp; 
	}
	else {
		int siz = s.size();
		x = siz - 1 - x , y = siz - 1 - y , swap(x , y);
		x ++ , y ++;
		int len = y - x + 1;
		int tmp = v2[x - 1][ty] * h[len][ty] % mod;
		tmp = v2[y][ty] - tmp;
		tmp = (tmp % mod + mod) % mod;
		return tmp; 
	}
}
int Query(int a , int b , int x , int y){
	// DB4("vs = " , "" , query(a , b , 0 , 0) , query(x , y , 0 , 1));
	if(query(a , b , 0 , 0) != query(x , y , 0 , 1)) return 0;
	// DB4("vs = " , "" , query(a , b , 1 , 0) , query(x , y , 1 , 1));
	if(query(a , b , 1 , 0) != query(x , y , 1 , 1)) return 0;
	return 1;
}
int ans[MAX] , dp[MAX][MAX];
void DP(int l , int r){
	if(l == r){
		dp[l][r] = 1;
		return;
	}
	else {
		int len = r - l + 1;
		if(len % 2 == 0){
			int mid = (l + r) / 2;
			if(Query(l , mid , mid + 1 , r)) dp[l][r] = dp[l][mid] + 1;
		}
		else {
			len /= 2;
			if(Query(l , l + len - 1 , r - len + 1 , r))
				dp[l][r] = dp[l][l + len - 1] + 1;
		}
	}
}
int32_t main(){
	srand(time(NULL));
	AC = rand() % 100 + 37;
	cin >> s;

	h[0][0] = h[0][1] = 1;
	REP(i , 1 , MAX){
		h[i][0] = h[i - 1][0] * AC % mod;
		h[i][1] = h[i - 1][1] * BC % mod;
	}
	REP(i , 1 , s.size() + 1){
		v[i][0] = (v[i - 1][0] * AC + s[i - 1]) % mod;
		v[i][1] = (v[i - 1][1] * BC + s[i - 1]) % mod;
	}
	reverse(ALL(s));
	REP(i , 1 , s.size() + 1){
		v2[i][0] = (v2[i - 1][0] * AC + s[i - 1]) % mod;
		v2[i][1] = (v2[i - 1][1] * BC + s[i - 1]) % mod;
	}
	REP(i , 0 , s.size()){
		REP(j , 0 , s.size()){
			int l = j , r = j + i;
			if(r >= s.size()) break;
			DP(l , r);
			if(dp[l][r] > 0){
				ans[dp[l][r]] ++;
				// DB4("val = " , l , r , dp[l][r]);
			}
		}
	}
	RREP(i , s.size() + 1 , 1)
		ans[i] += ans[i + 1];
	REP(i , 1 , s.size() + 1) 
		cout << ans[i] << " " ;cout << endl;
    return 0;
}