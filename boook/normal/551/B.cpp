#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

string s , x[2];
int h[30] , cc[2][30] , tmp[30];
int32_t main(){
	IOS;
	cin >> s >> x[0] >> x[1];
	REP(i , 0 , s.size())
		h[s[i] - 'a'] ++;
	REP(i , 0 , 2){
		REP(j , 0 , x[i].size())
			cc[i][x[i][j] - 'a'] ++;
	}
	PII ans = mp(0 , 0);
	REP(i , 0 , MAX){
		int ok = 1 , sum = INF;
		REP(j , 0 , 26){
			tmp[j] = h[j] - cc[0][j] * i;
			if(tmp[j] < 0){ ok = 0 ; break;}
		}
		if(ok == 0) break;
		REP(j , 0 , 26){
			if(cc[1][j] == 0) continue;
			sum = min(sum , tmp[j] / cc[1][j]);
		}
		ans = max(ans , mp(sum + i , i));
	}
	REP(times , 0 , ans.B){
		cout << x[0] ;
		REP(i , 0 , x[0].size()) h[x[0][i] - 'a'] --;
	}
	REP(times , 0 , ans.A - ans.B){
		cout << x[1] ;
		REP(i , 0 , x[1].size()) h[x[1][i] - 'a'] --;
	}
	REP(i , 0 , 26){
		while(h[i] --) cout << char('a' + i) ;
	}
	cout << endl;
    return 0;
}