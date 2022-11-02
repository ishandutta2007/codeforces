/*input
100 1000
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
#define INF 0x3f3f3f3f
#define mod 1000000007LL

map<int , int> cc;
void solveinit(){
 cc[3] = 1 , cc[4] = 2 , cc[5] = 1 , cc[7] = 2 , cc[9] = 0 , cc[13] = 1 , cc[15] = 2 , 
 cc[19] = 0 , cc[27] = 1 , cc[39] = 2 , cc[40] = 0 , cc[57] = 2 , cc[58] = 1 , cc[81] = 2 , 
 cc[85] = 0 , cc[120] = 2 , cc[121] = 1 , cc[174] = 2 , cc[179] = 0 , cc[255] = 2 , cc[260] = 1 , 
 cc[363] = 2 , cc[382] = 0 , cc[537] = 2 , cc[544] = 1 , cc[780] = 2 , cc[805] = 0 , cc[1146] = 2 , 
 cc[1169] = 1 , cc[1632] = 2 , cc[1718] = 0 , cc[2415] = 2 , cc[2447] = 1 , cc[3507] = 2 , 
 cc[3622] = 0 , cc[5154] = 2 , cc[5260] = 1 , cc[7341] = 2 , cc[7730] = 0 , cc[10866] = 2 , 
 cc[11011] = 1 , cc[15780] = 2 , cc[16298] = 0 , cc[23190] = 2 , cc[23669] = 1 , cc[33033] = 2 , 
 cc[34784] = 0 , cc[48894] = 2 , cc[49549] = 1 , cc[71007] = 2 , cc[73340] = 0 , cc[104352] = 2 , 
 cc[106510] = 1 , cc[148647] = 2 , cc[156527] = 0 , cc[220020] = 2 , cc[222970] = 1 , 
 cc[319530] = 2 , cc[330029] = 0 , cc[469581] = 2 , cc[479294] = 1 , cc[668910] = 2 , 
 cc[704371] = 0 , cc[990087] = 2 , cc[1003364] = 1 , cc[1437882] = 2 , cc[1485130] = 0 , 
 cc[2113113] = 2 , cc[2156822] = 1 , cc[3010092] = 2 , cc[3169669] = 0 , cc[4455390] = 2 , 
 cc[4515137] = 1 , cc[6470466] = 2 , cc[6683084] = 0 , cc[9509007] = 2 , cc[9705698] = 1 , 
 cc[13545411] = 2 , cc[14263510] = 0 , cc[20049252] = 2 , cc[20318116] = 1 , cc[29117094] = 2 , 
 cc[30073877] = 0 , cc[42790530] = 2 , cc[43675640] = 1 , cc[60954348] = 2 , cc[64185794] = 0 , 
 cc[90221631] = 2 , cc[91431521] = 1 , cc[131026920] = 2 , cc[135332446] = 0 , cc[192557382] = 2 , 
 cc[196540379] = 1 , cc[274294563] = 2 , cc[288836072] = 0 , cc[405997338] = 2 , 
 cc[411441844] = 1 , cc[589621137] = 2 , cc[608996006] = 0 , cc[866508216] = 2 , 
 cc[884431705] = 1 , cc[10000000000] = -1;
}
int n , p , x[2000][10];
int solve(int from , int to){
	return (from + to) * (from - to + 1) / 2 % mod;
}
int32_t main(){
	IOS;
	// cc[0] = 0;
	// int pre = 0;
	// // REP(i , 3 , 100 + 1){
	// REP(i , 3 , 1000000000 + 1){
	// 	if(i % 10000000 == 0) DBGG("now = " , i);
	// 	int v1 = i / 3 , v2 = i - i / 3 , now;
	// 	v1 = (*prev(cc.upper_bound(v1))).B;
	// 	v2 = (*prev(cc.upper_bound(v2))).B;
	// 	if(v1 != 0 && v2 != 0) now = 0;
	// 	else if(v1 != 1 && v2 != 1) now = 1;
	// 	else now = 2;
	// 	if(now != pre) pre = now , cc[i] = now;
	// }
	// for(auto to : cc){
	// 	cout << "a[" << to.A << "] = " << to.B << endl;
	// }
	solveinit();
	cin >> n >> p;
	int pre = 1 , frv = 0;
	for(auto to : cc){
		int val = min(to.A - 1 , p - 1);
		x[1][frv] = (x[1][frv] + solve(p - pre , p - val)) % mod;
		// DBGG(pre , val);
		if(val == p - 1) break;
		else pre = to.A , frv = to.B;
	}
	// DB4(x[1][0] , x[1][1] , x[1][2] , "");
	REP(i , 1 , n){
		REP(j , 0 , 4){
			REP(k , 0 , 3){
				x[i + 1][j ^ k] = (x[i + 1][j ^ k] + x[i][j] * x[1][k]) % mod;
			}
		}
	}
	cout << (x[n][1] + x[n][2] + x[n][3]) % mod << endl;
    return 0;
}