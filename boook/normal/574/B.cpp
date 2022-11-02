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
#define MAX 4010
#define INF 0x3f3f3f3f

int n , m , o[MAX];
int p[MAX][MAX];
vector<int> v[MAX];
int32_t main(){

	cin >> n >> m;
	REP(i , 0 , m){
		int q , w;
		cin >> q >> w;
		o[q] ++ , o[w] ++;
		v[q].pb(w) , v[w].pb(q);
		p[q][w] = 1 , p[w][q] = 1;
	}
	int ans = INF;
	REP(i , 1 , n + 1){
		REP(j , 0 , v[i].size()){
			REP(k , j + 1 , v[i].size()){
				int a = v[i][j];
				int b = v[i][k];
				if(p[a][b] == 1) ans = min(ans , o[i] + o[a] + o[b] - 6);
			}
		}
	}
	cout << ((ans == INF) ? -1 : ans) << endl;
    return 0;
}