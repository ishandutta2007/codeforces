/*input
10
-10 -9 -8 -7 -6 6 7 8 9 10
0000111110
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX];
string s;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) cin >> x[i];
	cin >> s;
	int smll = -1000000000 , bigl = 1000000000;
	int smlr = -1000000000 , bigr = 1000000000;
	REP(i , 4 , n){
		int same = 1;
		if(s[i - 1] != s[i - 2]) same = 0;
		if(s[i - 1] != s[i - 3]) same = 0;
		if(s[i - 1] != s[i - 4]) same = 0;

		if(s[i - 1] == '0' && s[i] == '0'){
			if(same){
				int tmp = -INF;
				REP(j , 0 , 4 + 1) tmp = max(tmp , x[i - j]);
				bigl = min(bigl , tmp);
			}
		}
		if(s[i - 1] == '0' && s[i] == '1'){
			int tmp = -INF;
			REP(j , 0 , 4 + 1) tmp = max(tmp , x[i - j]);
			smll = max(smll , tmp + 1);
		}
		if(s[i - 1] == '1' && s[i] == '0'){
			int tmp = INF;
			REP(j , 0 , 4 + 1) tmp = min(tmp , x[i - j]);
			bigr = min(bigr , tmp - 1);	
		}
		if(s[i - 1] == '1' && s[i] == '1'){
			if(same){
				int tmp = INF;
				REP(j , 0 , 4 + 1) tmp = min(tmp , x[i - j]);
				smlr = max(smlr , tmp);	
			}
		}
	}
	cout << smll << " " << bigr << endl;
    return 0;
}