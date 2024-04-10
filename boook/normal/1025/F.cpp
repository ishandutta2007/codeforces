/*input
7
0 -1000000000
-5 -5
5 -5
-5 0
5 0
-2 2
2 2
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
#define MAX 2002
#define INF 0x3f3f3f3f

PII p[MAX];
int n , idx[MAX] , pos[MAX];
vector<PII> v;

PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
PII operator - (PII x , PII y){ return mp(x.A - y.A , x.B - y.B); }

int cmp1(PII x , PII y){
	x = p[x.B] - p[x.A];
	y = p[y.B] - p[y.A];
	if(x.A == 0 || y.A == 0) return (x.A == 0) < (y.A == 0);
	if(x.A < 0) x.A *= -1 , x.B *= -1;
	if(y.A < 0) y.A *= -1 , y.B *= -1;
	return x.B * y.A < y.B * x.A;
}
inline int C(int now){ return now * (now - 1) / 2; }
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> p[i].A >> p[i].B;
	sort(p + 1 , p + 1 + n);
	REP(i , 1 , n + 1) idx[i] = i , pos[i] = i;
	REP(i , 1 , n + 1) REP(j , i + 1 , n + 1) v.pb(mp(i , j));
	sort(ALL(v) , cmp1);

	int ans = 0;
	for(auto line : v){
		int fr = pos[line.A] , ba = pos[line.B] , now;
		if(fr > ba) swap(fr , ba);

		ans += C(fr - 1) * C(n - ba);
		swap(idx[fr] , idx[ba]) , swap(pos[line.A] , pos[line.B]);
	}
	cout << ans << endl;
    return 0;
}