/*input
0 1000 24 36
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
#define MAX 
#define INF 0x3f3f3f3f

int a , b , l , r;
map<int , int> cc , dd;
int32_t main(){
	IOS;
	cin >> l >> r >> a >> b;
	int aaa = a , bbb = b;
	REP(i , 2 , a + 1){
		if(i * i > a) break;
		int cnt = 1;
		while(a % i == 0) a /= i , cnt *= i;
		if(cnt != 1) cc[i] = cnt;
	}
	cc[a] = a;

	REP(i , 2 , b + 1){
		if(i * i > b) break;
		int cnt = 1;
		while(b % i == 0) b /= i , cnt *= i;
		if(cnt != 1) dd[i] = cnt;
	}
	dd[b] = b;

	set<int> st;
	for(auto to : cc) st.insert(to.A);
	for(auto to : dd) st.insert(to.A);

	for(auto to : cc) if(dd[to.A] == 0) dd[to.A] = 1;
	for(auto to : dd) if(cc[to.A] == 0) cc[to.A] = 1;

	for(auto to : st) if(cc[to] > dd[to]) return cout << 0 << endl , 0;

	// for(auto to : st) cout << to << endl;
	// for(auto to : cc) DBGG(to.A , to.B);
	// for(auto to : dd) DBGG(to.A , to.B);
				// DBGG("base = " , base);
		// cout << st.size() << endl;

	set<PII> ans;
	REP(i , 0 , (1 << st.size())){
		// DBGG("i = " , i);

		int val = i , v1 = 1 , v2 = 1;
		for(auto to : st){
			if(val % 2 == 0) v1 *= cc[to] , v2 *= dd[to];
			if(val % 2 == 1) v1 *= dd[to] , v2 *= cc[to];
			val /= 2;
		}
		// DBGG(v1 , v2);
		if(l <= v1 && v1 <= r && l <= v2 && v2 <= r){
			ans.insert(mp(v1 , v2));
		}
	}
	cout << ans.size() << endl;
    return 0;
}