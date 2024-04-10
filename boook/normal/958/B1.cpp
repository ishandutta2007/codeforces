/*input
4
1 2
4 3
1 4
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
#define MAX 10000
#define INF 0x3f3f3f3f

int n;
vector<int> v[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 2 , n + 1) {
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int cnt = 0;
	REP(i , 1 , n + 1) cnt += v[i].size() == 1;
	cout << cnt << endl;
    return 0;
}