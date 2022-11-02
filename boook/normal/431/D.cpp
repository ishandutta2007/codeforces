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
#define MAX 70
#define INF 0x3f3f3f3f
int ha(int tmp , int k){
	map<int , int> cc;
	cc.clear();	
	REP(i , 1 , tmp + 1){
		bitset<100> dp(i);
		cc[dp.count()] ++;
		// cout << i << " " << dp.count() << endl;
	}
	return cc[k];
}
int c[MAX][MAX];
int C(int a , int b){
	if(b < 0 || a < b) return 0;
	if(c[a][b] != -1) return c[a][b];
	if(a == b || b == 0) return c[a][b] = 1;
	else return c[a][b] = C(a - 1 , b) + C(a - 1 , b - 1);
}
int SUM(int now , int k){

	int have = 0 , ans = 0;
	RREP(i , 61 , 0){
		if(now & (1LL << i)){
			ans += C(i , k - have);
			have ++;
		}
	}
	if(have == k) ans ++;

	// DBGG("my = " , ans);
	// DBGG("good ans = " , ha(now , k));
	// assert(ans == ha(now , k));
	return ans;
}
int check(int n , int k){
	return SUM(n + n , k) - SUM(n , k);
}
int m , k;
int32_t main(){
		MEM(c , -1);
	cin >> m >> k;
	int ans = 0;
	RREP(i , 61 , 0){
		int to = ans + (1LL << i);
		if(to < 1000000000000000000LL && check(to , k) <= m) ans = to;
	}
	cout << ans << endl;
    return 0;
}