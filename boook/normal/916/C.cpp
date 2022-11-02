/*input
5 10
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
#define MAX 
#define INF 0x3f3f3f3f
#define N 10430579

int n , m;
set<PII> cc;
int32_t main(){
	IOS , cin >> n >> m;

	if(n == 2){
		cout << "2 2" << endl;
		cout << "1 2 2" << endl;
		return 0;
	}
	else {
		cout << 2 << " " << N << endl;
		cc.insert(mp(1 , n));
		cout << "1 " << n << " 2" << endl;
		int pre = n , val = N - 2;
		REP(i , 2 , n - 1){
			cout << i << " " << i + 1 << " " << 3 << endl;
			val -= 3;
			cc.insert(mp(i , i + 1));
		}
		cc.insert(mp(n - 1 , n));
		cout << n - 1 << " " << n << " " << val << endl;
		REP(i , 1 , n + 1){
			if(cc.size() == m) break;
			REP(j , i + 1 , n + 1){
				if(cc.size() == m) break;
				if(cc.size() != m){
					if(cc.find(mp(i , j)) == cc.end()){
						cout << i << " " << j << " " << N + 1 << endl;
						cc.insert(mp(i , j));
					}
				}
			}
		}
	}

    return 0;
}