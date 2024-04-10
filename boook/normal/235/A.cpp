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

int n;
int F(int a , int b , int c){
	int tmp = __gcd(a , b);
	int val = a / tmp * b;
	tmp = __gcd(val , c);
	return val / tmp * c;
}
int32_t main(){
	cin >> n;
	if(n == 1) cout << 1 << endl;
	else if(n == 2) cout << 2 << endl;
	else if(n == 3) cout << 6 << endl;
	else {
		int ans = 0 , x = max(1LL , n - 10);
		REP(i , x , n + 1){
			REP(j , i , n + 1){
				REP(k , j , n + 1)
					ans = max(ans , F(i , j , k));
			}
		}
		cout << ans << endl;
	}
    return 0;
}