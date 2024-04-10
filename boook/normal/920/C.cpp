/*input
6
1 2 5 3 4 6
01010
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
#define MAX 200900
#define INF 0x3f3f3f3f

struct N{
	int x[MAX] , big[MAX] , sml[MAX] ;
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){
		a = Find(a) , b = Find(b);
		x[a] = b;
		sml[b] = min(sml[a] , sml[b]);
		big[b] = max(big[a] , big[b]);
	}
	int operator[](int now){ return Find(now); }
} ds;
int n , x[MAX];
string s;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	ds.init();
	REP(i , 1 , n + 1) ds.sml[i] = ds.big[i] = x[i];
	cin >> s;
	REP(i , 1 , n + 0) if(s[i - 1] == '1') ds.Union(i , i + 1);
	REP(i , 2 , n + 1){
		if(ds[i] != ds[i - 1]){
			int a = ds[i] , b = ds[i - 1];
			if(ds.big[b] <= ds.sml[a]);
			else return cout << "NO" << endl , 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}