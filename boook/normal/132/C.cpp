/*input

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
#define MAX 150
#define INF 0x3f3f3f3f

string s;
int k , sml[MAX][MAX][2] , big[MAX][MAX][2];
int32_t main(){
	IOS;
	cin >> s , s = " " + s;	
	cin >> k;
	REP(i , 0 , MAX) REP(j , 0 , MAX) REP(ii , 0 , 2) sml[i][j][ii] = INF;
	REP(i , 0 , MAX) REP(j , 0 , MAX) REP(ii , 0 , 2) big[i][j][ii] = -INF;
	sml[0][0][0] = big[0][0][0] = 0;
	REP(i , 1 , s.size()){
		REP(j , 0 , k + 1){
			if(s[i] == 'F'){
				      sml[i][j][0] = min(sml[i][j][0] , sml[i - 1][j][0] + 1);
				if(j) sml[i][j][0] = min(sml[i][j][0] , sml[i - 1][j - 1][1]);

					  sml[i][j][1] = min(sml[i][j][1] , sml[i - 1][j][1] - 1);
				if(j) sml[i][j][1] = min(sml[i][j][1] , sml[i - 1][j - 1][0]);

				      big[i][j][0] = max(big[i][j][0] , big[i - 1][j][0] + 1);
				if(j) big[i][j][0] = max(big[i][j][0] , big[i - 1][j - 1][1]);

					  big[i][j][1] = max(big[i][j][1] , big[i - 1][j][1] - 1);
				if(j) big[i][j][1] = max(big[i][j][1] , big[i - 1][j - 1][0]);
			}
			if(s[i] == 'T'){
				if(j) sml[i][j][0] = min(sml[i][j][0] , sml[i - 1][j - 1][0] + 1);
					  sml[i][j][0] = min(sml[i][j][0] , sml[i - 1][j][1]);

				if(j) sml[i][j][1] = min(sml[i][j][1] , sml[i - 1][j - 1][1] - 1);
					  sml[i][j][1] = min(sml[i][j][1] , sml[i - 1][j][0]);

				if(j) big[i][j][0] = max(big[i][j][0] , big[i - 1][j - 1][0] + 1);
					  big[i][j][0] = max(big[i][j][0] , big[i - 1][j][1]);

				if(j) big[i][j][1] = max(big[i][j][1] , big[i - 1][j - 1][1] - 1);
				 	  big[i][j][1] = max(big[i][j][1] , big[i - 1][j][0]);
			}
		}
	}
	int ans = 0;
	for(int i = k ; i >= 0 ; i -= 2){
		ans = max(ans , -sml[s.size() - 1][i][0]);
		ans = max(ans , -sml[s.size() - 1][i][1]);
		ans = max(ans , big[s.size() - 1][i][0]);
		ans = max(ans , big[s.size() - 1][i][1]);
	}
	cout << ans << endl;
    return 0;
}