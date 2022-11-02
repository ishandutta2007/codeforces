/*input
4
-1 0
0 -1
1 0
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , sol[MAX];
PII x[MAX];
int id(PII now){
	if(now.A >  0 && now.B == 0) return 1;
	if(now.A >  0 && now.B >  0) return 2;
	if(now.A == 0 && now.B >  0) return 3;
	if(now.A <  0 && now.B >  0) return 4;
	if(now.A <  0 && now.B == 0) return 5;
	if(now.A <  0 && now.B <  0) return 6;
	if(now.A == 0 && now.B <  0) return 7;
	if(now.A >  0 && now.B <  0) return 8;
}
int cmp(int aa , int bb){
	PII a = x[aa] , b = x[bb];
	if(id(a) != id(b)) return id(a) < id(b);
	int xx = a.B * b.A , yy = b.B * a.A;
	return xx < yy;
}
typedef pair<int , PII> PI;
PI F(int a , int b){
	int res = 1;
	int aa = (x[a].A * x[a].A) + (x[a].B * x[a].B);
	int bb = (x[b].A * x[b].A) + (x[b].B * x[b].B);
	int cc = (x[a].A - x[b].A) * (x[a].A - x[b].A)
		   + (x[a].B - x[b].B) * (x[a].B - x[b].B);

	if(aa + bb - cc < 0) res = -1;

	int vv = (aa + bb - cc) * (aa + bb - cc);

	return mp(res , mp(vv , aa * bb * 4));
}
int cmp2(PI a , PI b){
	if(a.A != b.A) return a.A > b.A;
	__float128 v1 = (__float128)a.B.A * (__float128)b.B.B;
	__float128 v2 = (__float128)a.B.B * (__float128)b.B.A;
	if(a.A ==  1) return v1 > v2;
	if(a.A == -1) return v1 < v2;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) cin >> x[i].A >> x[i].B;
	REP(i , 0 , n) sol[i] = i;
	sort(sol , sol + n , cmp);
	PII ans = mp(sol[0] , sol[1]);
	PI val = F(sol[0] , sol[1]);
	REP(i , 0 , n){
		PI tmp = F(sol[i] , sol[(i + 1) % n]);
		// DB4(sol[i] , sol[(i + 1) % n] , tmp.A , "");
		if(cmp2(tmp , val)){
			val = tmp;
			ans = mp(sol[i] , sol[(i + 1) % n]);
		}
		// DBGG(ans.A , ans.B);
	}
	cout << ans.A + 1 << " " << ans.B + 1 << endl;
    return 0;
}