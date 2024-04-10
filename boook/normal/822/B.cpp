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
string a , b;

int32_t main(){
	cin >> n >> m;
	cin >> a >> b;
	int ans = INF;
	vector<int> sol , tmp;
	REP(i , 0 , b.size()){
		int cnt = 0;
		tmp.clear();
		REP(j , 0 , a.size()){
			int q = i + j , w = j;
			if(q >= b.size()){
				cnt = INF;
				break;
			}
			else if(b[q] != a[w]) cnt++ , tmp.pb(j + 1);
		}
		if(cnt < ans){
			ans = min(ans , cnt);
			sol = tmp;
		}
	}
	cout << ans << endl;
	for(auto to : sol) cout << to << " " ;cout << endl;
    return 0;
}