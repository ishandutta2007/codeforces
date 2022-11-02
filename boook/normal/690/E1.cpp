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
#define MAX 500
#define INF 0x3f3f3f3f

int t , n , m;
int x[MAX][MAX];
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 0 , t){
		cin >> n >> m;
		REP(i , 0 , n) REP(j , 0 , m){
			cin >> x[i][j];
		}
		if(n == 1){
			cout << "YES" << endl;
			continue;
		}
		int ok = 1 , tmp = max(n / 2 - 2 , 0);
		REP(j , tmp , min(tmp + 2 , n - 1)){
			int cnt = 0;
			REP(i , 0 , m){
				cnt += abs(x[j][i] - x[j + 1][i]);
			}
			if(cnt > 20 * m) ok = 0;
		}
		cout << ((ok == 0) ? "YES" : "NO") << endl;
	}
    return 0;
}