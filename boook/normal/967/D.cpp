/*input
5 12 20
7 8 4 11 9
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , a , b , sw = 0;
PII x[MAX] , ok[MAX];
vector<int> v1 , v2;
void Print(){
	cout << "Yes" << endl;
	if(sw) swap(v1 , v2);
	cout << v1.size() << " " << v2.size() << endl;
 	for(auto to : v1) cout << to << " "; cout << endl;
	for(auto to : v2) cout << to << " "; cout << endl;
	exit(0); 
}
void solve(){
	int f1 , t1 , f2 , t2;
	for(f1 = t1 = n ; t1 > 0 ; t1 --){
		if((f1 - t1 + 1) * x[t1].A >= a) break;
	}
	for(f2 = t2 = t1 - 1 ; t2 > 0 ; t2 --){
		if((f2 - t2 + 1) * x[t2].A >= b) break;
	}
	// DB4(f2 , t2 , f1 , t1);
	if(t2 > 0){
		REP(i , t1 , f1 + 1) v1.pb(x[i].B);
		REP(i , t2 , f2 + 1) v2.pb(x[i].B);
		Print();
	}
}
int32_t main(){
	IOS;
	cin >> n >> a >> b;
	REP(i , 1 , n + 1) cin >> x[i].A , x[i].B = i;
	sort(x + 1 , x + 1 + n);
	solve();
	swap(a , b) , sw = 1;
	solve();
	cout << "No" << endl;
    return 0;
}