/*input
10 3
Mn Co Li Mg C P F Zn Sc K
Sn Pt Y
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
#define MAX 200
#define INF 0x3f3f3f3f

string ss[103] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl",
                            "Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se",
                            "Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb",
                            "Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er",
                            "Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At",
                            "Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No",
                            "Lr"};

int n , m , x[MAX] , y[MAX] , a[1 << 18] , dp[1 << 18] , pa[1 << 18];
string s;
int32_t main(){
	IOS;
	map<string , int> val;
	REP(i , 0 , 103) val[ss[i]] = i + 1;
	cin >> n >> m;

	REP(i , 0 , n) cin >> s , x[i] = val[s];
	REP(i , 0 , m) cin >> s , y[i] = val[s];
	// REP(i , 0 , n) cout << x[i] << " " ; cout << endl;
	// REP(i , 0 , m) cout << y[i] << " " ; cout << endl;
 	REP(i , 1 , (1 << n)){
		int low = i & -i;
		a[i] = a[i ^ low] + x[__lg(low)];
	}
	REP(i , 1 , (1 << n)){
		for(int j = i ; j ; j = (j - 1) & i){
			int to = i ^ j;
			if(a[j] == y[dp[to]] && dp[i] < dp[to] + 1){
				dp[i] = dp[to] + 1;
				pa[i] = to;
			}
		}
	}
	if(dp[(1 << n) - 1] != m) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int now = (1 << n) - 1;
		RREP(ii , m - 1 , 0){
			int pick = now ^ pa[now];
			// DBGG("pick = " , pick);
			vector<int> sol;
			while(pick){
				int low = pick & -pick;
				sol.pb(__lg(low));
				pick -= low;
			}
			cout << ss[x[sol[0]] - 1];
			REP(i , 1 , sol.size())cout << '+' << ss[x[sol[i]] - 1];
			cout << "->" << ss[y[ii] - 1] << endl;
			now = pa[now];
		}
	}
    return 0;
}