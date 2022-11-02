/*input
13 4
10
5
4
8
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , k , now;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 0 , k){
		cin >> now;
		if(now % 2 == 1) cout << (now + 1) / 2 << endl;
		else {
			int tmp = n - now / 2;
			while(tmp % 2 == 0) tmp /= 2;
			cout << n + 1 - (tmp + 1) / 2 << endl;
		}
	}
    return 0;
}