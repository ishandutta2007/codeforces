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
#define MAX 
#define INF 0x3f3f3f3f

int ans , lim;
int N(int a , int b , int c){
	int cnt = 0;
	REP(i , 0 , lim + 1){
		int now = a + i , have = lim - i;
		int tmp = min(have , now - (b + c));
		if(tmp < 0) continue;
		cnt += (tmp + 1) * (tmp + 2) / 2;
	}
	return cnt;
}
int32_t main(){
	int a , b , c;
	cin >> a >> b >> c >> lim;
	REP(i , 0 , lim + 1) ans += (i + 2) * (i + 1) / 2;
	ans -= N(a , b , c);
	ans -= N(b , a , c);
	ans -= N(c , a , b);
	cout << ans << endl;
    return 0;
}