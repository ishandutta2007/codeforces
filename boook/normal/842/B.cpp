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
#define MAX 
#define INF 0x3f3f3f3f

double r , d;
int n;
int32_t main(){
	cin >> r >> d;
	d = r - d;
	cin >> n;
	int cnt = 0;
	REP(i , 1 , n + 1){
		double q , w , e;
		cin >> q >> w >> e;
		double dis = sqrt((long double)(q * q + w * w));
		if(d < 1){
			if(dis + e <= r && dis - e >= -r && dis <= r) cnt ++;
		}
		else {
			if(dis + e <= r && dis - e >= d && dis <= r) cnt ++;
		}
		// cout << cnt << endl;
	}
	cout << cnt << endl;
    return 0;
}