/*input
10
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
#define MAX 10000009
#define INF 0x3f3f3f3f

int dv[MAX] , ph[MAX] , p[MAX] , x[MAX] , po = 0;
int n , v1 = 0 , v2 = 0 , v3 = 0;
int32_t main(){
	IOS;
	cin >> n , ph[1] = 1;
	REP(i , 2 , MAX){
		if(dv[i] == 0) dv[i] = p[po ++] = i;
		REP(j , 0 , po){
			if(i * p[j] >= MAX) break;
			dv[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
		if((i / dv[i]) % dv[i] == 0) 
			 ph[i] = ph[i / dv[i]] * dv[i];
		else ph[i] = ph[i / dv[i]] * (dv[i] - 1);
	}
	int res = 0;
	REP(i , 2 , n + 1) v1 += i - 1 - ph[i];

	REP(i , 2 , n + 1) x[dv[i]] ++;
	REP(i , 2 , n + 1) x[i] += x[i - 1];
	REP(i , 2 , n + 1) v2 += x[n / dv[i]];
	REP(i , 2 , n + 1) if(dv[i] * dv[i] <= n) v2 --;
	v2 /= 2 , v2 -= v1;

	int las = n - 1;
	REP(i , 2 , n + 1) if(dv[i] == i && i * 2 > n) las --;
	v3 = las * (las - 1) / 2 - v1 - v2;
	cout << v1 * 1 + v2 * 2 + v3 * 3 << endl;
    return 0;
}