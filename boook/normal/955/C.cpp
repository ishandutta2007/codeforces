/*input
1
1 1000000000000000000
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define ALL(i) i.begin() , i.end()
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 1000000000000000000LL

vector<int> v;

int32_t main(){
	IOS;
	REP(i , 2 , 1000004) if((int)sqrt(i) * (int)sqrt(i) != i){
		int val = i;
		REP(j , 1 , 100){
			if(INF / val / i >= 1){
				val *= i;
				if(j % 2 == 0){
					if(j % 2 == 1){
						cout << i << " " << j << " " << val << endl;
						return 0;
					}
					v.pb(val);
				}
			}
		}
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	int n , ql , qr;
	cin >> n;
	REP(times , 0 , n){
		cin >> ql >> qr , ql --;
		int r = sqrt((long double)qr) , l = sqrt((long double)ql);
		// DB4("l = " , l , "r = " , r);
		int res = upper_bound(ALL(v) , qr) - upper_bound(ALL(v) , ql);
		cout << res + r - l << endl;
	}
    return 0;
}