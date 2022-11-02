/*input
5
01 07
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
#define MAX 
#define INF 0x3f3f3f3f

int n , x , y;
int check(int a , int b){
	while(a){
		if(a % 10 == 7) return 1;
		a /= 10;
	}
	while(b){
		if(b % 10 == 7) return 1;
		b /= 10;
	}
	return 0;
}
int32_t main(){
	cin >> n >> x >> y;
	int ans = 0;
	while(check(x , y) == 0){
		ans ++;
		int tmp = x * 60 + y - n;
		tmp = (tmp + 24 * 60) % (24 * 60);
		x = tmp / 60;
		y = tmp % 60;
	}
	cout << ans << endl;
    return 0;
}