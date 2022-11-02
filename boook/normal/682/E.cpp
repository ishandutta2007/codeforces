/*input
4 1
0 0
1 0
0 1
1 1
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
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f

int n , m;
PII x[MAX];
PII operator + (PII a , PII b){ return mp(a.A + b.A , a.B + b.B); }
PII operator - (PII a , PII b){ return mp(a.A - b.A , a.B - b.B); }
inline int calc(int a , int b , int c){
	PII xx = x[b] - x[a] , yy = x[c] - x[a];
	return abs(xx.A * yy.B - xx.B * yy.A);
}
void Print(PII now){ cout << now.A << " " << now.B << endl; }
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
	int val = 0 , a = 1 , b = 2 , c = 3;
	while(1){
		int ok = 0;
		REP(i , 1 , n + 1) if(!ok && calc(i , b , c) > val) a = i , val = calc(a , b , c) , ok = 1;
		REP(i , 1 , n + 1) if(!ok && calc(a , i , c) > val) b = i , val = calc(a , b , c) , ok = 1;
		REP(i , 1 , n + 1) if(!ok && calc(a , b , i) > val) c = i , val = calc(a , b , c) , ok = 1;
		if(ok == 0) break;
	}
	Print(x[a] + (x[b] - x[a]) + (x[c] - x[a]));
	Print(x[b] + (x[a] - x[b]) + (x[c] - x[b]));
	Print(x[c] + (x[a] - x[c]) + (x[b] - x[c]));
    return 0;
}