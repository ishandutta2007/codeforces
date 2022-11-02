
 #include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define INF 0x3f3f3f3f

int n , m , k;
int32_t main(){
    IOS;
    cin >> n >> m >> k , k ++;
	if(k <= n) cout << k << " " << 1 << endl;
	else {
		k -= n , k --;
		int val = k / (m - 1 + m - 1);
		int xx = n - val - val , yy = 2;
		k %= (m - 1 + m - 1);
		if(k < m - 1){
			cout << xx << " " << yy + k << endl;
		}
		else {
			k -= m - 1;
			xx -- , yy = m;
			cout << xx << " " << yy - k << endl;
		}
	}
    return 0;
}