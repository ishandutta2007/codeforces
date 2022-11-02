/*input
4
22 73 9
45 64 6
47 55 7
2 62 4
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int p[MAX];
vector<int> v[10];
int F(int now){
	if(now < 10) return now;
	int val = 1;
	while(now){
		if(now % 10 != 0) val *= now % 10;
		now /= 10;
	}
	return F(val);
}
int32_t main(){
	IOS;
	REP(i , 1 , MAX) v[F(i)].pb(i);
	int m;
	cin >> m;
	REP(i , 1 , m + 1){
		int l , r , k;
		cin >> l >> r >> k;
		cout << upper_bound(ALL(v[k]) , r) - lower_bound(ALL(v[k]) , l) << endl;
	}
    return 0;
}