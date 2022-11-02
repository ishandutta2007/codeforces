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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
vector<int> tmp;
int32_t main(){
	cin >> n;
	REP(i , 0 , n){
		int q;
		cin >> q;
		tmp.pb(q);
	}
	sort(ALL(tmp));
	cin >> m;
	REP(i , 0 , m){
		int q;
		cin >> q;
		int ans = upper_bound(ALL(tmp) , q) - tmp.begin();
		if(q < tmp[0]) cout << 0 << endl;

		else cout << ans << endl;

	}
    return 0;
}