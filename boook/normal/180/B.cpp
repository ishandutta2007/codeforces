/*input
10 66
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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
int solve(int a , int b){
	int tmp = __gcd(a , b) , val = b;
	while(val % tmp == 0 && tmp != 1) val /= tmp;
	if(val == 1) return 2;
	if(a % b == 1) return 3; 
	if(a % b == b - 1) return 11;
	return -1;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	int tmp = __gcd(n , m) , val = m , cnt = 0;
	while(val % tmp == 0 && tmp != 1) val /= tmp , cnt ++ , tmp = __gcd(n , val);
	if(val == 1){
		cout << "2-type" << endl;
		cout << cnt << endl;
		return 0;
	}
	if(solve(n , m) != -1) cout << solve(n , m) << "-type" << endl;
	else {
		REP(i , 1 , m + 1) REP(j , i , m + 1) REP(k , j , m + 1){
			if(solve(n , i) != -1 && solve(n , j) != -1 && solve(n , k) != -1){
				int v1 = i / __gcd(i , j) * j;
				int v2 = v1 / __gcd(v1 , k) * k;
				if(v2 == m){
					return cout << "6-type" << endl , 0;
				}
			}
		}
		cout << "7-type" << endl;
	}
    return 0;
}