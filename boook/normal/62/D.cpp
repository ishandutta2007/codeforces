/*input
3 8
1 20 5 1 3 20 6 3 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 2020
#define INF 0x3f3f3f3f

int m , x[MAX] , q[MAX];
int tmpl , tmpr , u[150];
int check(int l , int r){
	// DB4("now at check" , l , ',' , r);
	memset(u , 0 , sizeof u);
	REP(i , r + 1 , m + 1) u[x[i]] = i;
	REP(i , l + 1 , r + 0) if(u[x[i]] != 0) return tmpl = i , tmpr = u[x[i]] , 1;
	// DBGG("return 0" , "");
	return 0;
}
void R(int l , int r){
	// DBGG(l , r);
	while(l <= r){
		q[l] = r , q[r] = l;
		swap(x[l] , x[r]);
		l ++ , r --;
	}
	// REP(i , 1 , m + 1) cout << x[i] << " " ; cout << endl;
}

int32_t main(){
	IOS;
	cin >> m >> m , m ++;
	REP(i , 1 , m + 1) cin >> x[i];
	int ok = 0;

	RREP(i , m , 1){
		int same = 0;
		int fr = INF , fridx;
		int ba = INF , baidx;
		REP(j , i + 1 , m + 1) if(x[i] == x[j]) same = max(same , j);
		if(same == 0) continue;
		REP(j , i + 1 , m + 1) if(x[i] == x[j]){
			if(x[j - 1] > x[i + 1] && x[j - 1] < ba)
				ba = x[j - 1] , baidx = j;
			if(x[j + 1] > x[i + 1] && x[j + 1] < fr && j != same)
				fr = x[j + 1] , fridx = j;
		}
		int thr = INF;
		int tok = check(i , same);
		if(same != m && x[same + 1] > x[i + 1] && tok == 1) thr = x[same + 1];

	// if(x[1] == 68 && x[2] == 50 && x[3] == 12 && x[4] == 92 && i == 1782){
	// 	DBGG("Fr = " , fr);
	// 	DBGG("Ba = " , ba);
	// 	DBGG("tok = " , tok);
	// 	DBGG("i + 1 = " , x[same + 1]);
	// 	return 0;
	// }
		if(fr != INF || ba != INF || thr != INF){
			ok = i + 1;
			if(thr <= fr && thr <= ba){
				R(tmpl , tmpr);
				same = q[same];
				R(i , same);
				// cout << "to here" << endl;
			}
			else if(ba <= fr && ba <= thr) R(i , baidx);
			else if(fr <= ba && fr <= thr) R(fridx , same) , R(i , same);
		}
		if(ok) break;
	}
	// return 0;
	if(ok == 0) return cout << "No solution" << endl , 0;
	// DBGG("ok = " , ok);
	REP(i , ok , m + 1){
		int same = 0;
		int fr = x[i + 1] , fridx;
		int ba = x[i + 1] , baidx;
		REP(j , i + 1 , m + 1) if(x[i] == x[j]) same = max(same , j);
		if(same == 0) continue;
		REP(j , i + 1 , m + 1) if(x[i] == x[j]){
			if(x[j - 1] < ba)
				ba = x[j - 1] , baidx = j;
			if(x[j + 1] < fr && j != same)
				fr = x[j + 1] , fridx = j;
		}
		if(fr < x[i + 1] || ba < x[i + 1]){
			ok = i + 1;
			if(ba < fr) R(i , baidx);
			else R(fridx , same) , R(i , same);
		}
	}
	REP(i , 1 , m + 1) cout << x[i] << " " ; cout << endl;
    return 0;
}