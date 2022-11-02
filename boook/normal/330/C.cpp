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
#define MAX 500
#define INF 0x3f3f3f3f

int n , ok[MAX];
string s[MAX];
int32_t main(){
	cin >> n;
	REP(i , 0 , n) cin >> s[i];

	vector<int> q , w;
	REP(i , 0 , n){
		REP(j , 0 , n){
			if(s[i][j] == '.'){
				q.pb(j); break;
			}
		}
	}
	REP(i , 0 , n){
		REP(j , 0 , n){
			if(s[j][i] == '.'){
				w.pb(j);
				break;
			}
		}
	}
	if(q.size() == n){
		REP(i , 0 , q.size()){
			cout << i + 1 << " " << q[i] + 1 << endl;
 		}
	}
	else if(w.size() == n){
		REP(i , 0 , w.size()){
			cout << w[i] + 1 << " " << i + 1 << endl;
		}
	}
	else cout << -1 << endl;
    return 0;
}