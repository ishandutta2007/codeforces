/*input
3 3
1 7 6
2 15 12
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
#define MAX 110
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX] , ans[MAX][MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , m + 1) cin >> b[i];
	REP(bit , 0 , 40){
		vector<int> ok;
		REP(j , 1 , m + 1) if(b[j] & (1LL << bit)) ok.pb(j);
		for(int j = 1 ; j < ok.size() ; j += 2){
			b[ok[j - 0]] ^= (1LL << bit);
			b[ok[j - 1]] ^= (1LL << bit);
			ans[1][ok[j - 0]] ^= (1LL << bit);
			ans[1][ok[j - 1]] ^= (1LL << bit);
		}
		REP(i , 1 , n + 1) if(a[i] & (1LL << bit)){
			int idx = m;
			REP(j , 1 , m + 1) if(b[j] & (1LL << bit)){ idx = j; break; } 
			b[idx] ^= (1 << bit);
			ans[i][idx] ^= (1 << bit);
			a[i] ^= (1 << bit);
		}
		REP(j , 1 , m + 1) if(b[j] & (1LL << bit)) return cout << "NO" << endl , 0;
	}
	cout << "YES" << endl;
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}