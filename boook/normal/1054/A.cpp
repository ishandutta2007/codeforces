/*input
1 6 6 2 1 1
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

int x , y , z , v1 , v2 , v3;
int32_t main(){
	IOS;
	cin >> x >> y >> z >> v1 >> v2 >> v3;
	int las = abs(x - y);
	int walk = las * v1;
	int take = v2 * (abs(z - x) + abs(x - y)) + v3 + v3 + v3;
	// DBGG(walk , take);
	if(take <= walk) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}