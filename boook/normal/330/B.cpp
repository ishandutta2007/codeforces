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
#define MAX 50000
#define INF 0x3f3f3f3f

int n , m , no[MAX];
int32_t main(){
	cin >> n >> m;
	REP(i , 0 , m){
		int q , w;
		cin >> q >> w;
		no[q] = 1 , no[w] = 1;
	}
	cout << n - 1 << endl;
	REP(i , 1 , n + 1){
		if(no[i] == 0){
			REP(j , 1 , n + 1){
				if(i == j) continue;
				cout << i << " " << j << endl;
			}
			return 0;
		}
	}
    return 0;
}