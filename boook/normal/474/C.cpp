#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n;
PII x[10][2];
PII tmp[10];
PII TR(PII now , PII cen){
	PII qq = mp(now.A - cen.A , now.B - cen.B);
	qq = mp(-qq.B , qq.A);
	qq = mp(qq.A + cen.A , qq.B + cen.B);
	return qq;
}
int judge(){
	VI sol;
	REP(i , 4) REPNM(j , i + 1 , 4){
		if(tmp[i] == tmp[j]) return 0;
		int a = (tmp[i].A - tmp[j].A);
		int b = (tmp[i].B - tmp[j].B);
		sol.pb(a * a + b * b);
	}
	sort(ALL(sol));
	REP(i , 3) if(sol[i] != sol[i + 1]) return 0;
	if(sol[0] * 2 != sol[4] || sol[4] != sol[5]) return 0;
	return 1;
}
int32_t main(){
	cin >> n;
	REP(times , n){
		REP(i , 4) REP(j , 2) cin >> x[i][j].A >> x[i][j].B;
		int ok = INF;
		REP(q , 4) REP(w , 4) REP(e , 4) REP(r , 4) {
			REP(i , 4) tmp[i] = x[i][0];
			REP(i , q) tmp[0] = TR(tmp[0] , x[0][1]);
			REP(i , w) tmp[1] = TR(tmp[1] , x[1][1]);
			REP(i , e) tmp[2] = TR(tmp[2] , x[2][1]);
			REP(i , r) tmp[3] = TR(tmp[3] , x[3][1]);
			// cout << "------\n";
			// DB4(tmp[0].A , tmp[0].B , tmp[1].A , tmp[1].B);
			// DB4(tmp[2].A , tmp[2].B , tmp[3].A , tmp[3].B);
			if(judge()) ok = min(ok , q + w + e + r);
		}
		cout << ((ok == INF) ? -1 : ok) << endl;
	}
    return 0;
}