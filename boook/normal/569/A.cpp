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
#define MAX 200000
#define INF 0x3f3f3f3f

long double t , s , q;
int ans = 0;

int32_t main(){
	cin >> t >> s >> q;

	q = (q - 1) / q;
	while(1){
		ans ++;
		if(s == t){ break; }
		else{
			long double tt = s / (1 - q);
			s = fmin(tt , t);
			if(t - s < 0.00000001) break;
		}

	}
	cout << ans << endl;
    return 0;
}