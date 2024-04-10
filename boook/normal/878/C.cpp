/*input
3 2
2 3
1 1
3 2
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

int n , k;
struct N{
	int sml[10] , big[10] , siz;
	int operator < (const N to)const{
		REP(i , 0 , k){
			if(big[i] < to.sml[i]);
			else return 0;
		}
		return 1;
	}
};
set<N> cc;

int32_t main(){
	IOS , cin >> n >> k;
	REP(times , 1 , n + 1){
		N now;
		now.siz = 1;
		REP(i , 0 , k){
			int in; cin >> in;
			now.sml[i] = now.big[i] = in;
		}
		auto tol = cc.lower_bound(now);
		auto tor = cc.upper_bound(now);
		while(tol != tor){
			now.siz += (*tol).siz;
			REP(i , 0 , k){
				now.sml[i] = min(now.sml[i] , (*tol).sml[i]);
				now.big[i] = max(now.big[i] , (*tol).big[i]);
			}

			auto tmp = (next(tol));
			cc.erase(tol) , tol = tmp;
		}
		cc.insert(now);
		cout << (*prev(cc.end())).siz << endl;
	}
    return 0;
}