/*input
0 0 6 0 6 6 0 6
7 3 9 5 11 3 9 1
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
#define MAX 
#define INF 0x3f3f3f3f

int a[4][2] , b[4][2];
int solve(int xx , int yy){
	int smlx = b[0][0] , bigx = b[0][0];
	int smly = b[0][1] , bigy = b[0][1];
	REP(i , 0 , 4){
		smlx = min(smlx , b[i][0]);
		bigx = max(bigx , b[i][0]);

		smly = min(smly , b[i][1]);
		bigy = max(bigy , b[i][1]);
	}
	if(smlx <= xx && xx <= bigx && smly <= yy && yy <= bigy){
		cout << "YES" << endl;
		exit(0);
	}
}
int32_t main(){
	IOS;
	REP(i , 0 , 4) REP(j , 0 , 2) cin >> a[i][j];
	REP(i , 0 , 4) REP(j , 0 , 2) cin >> b[i][j];

	int smlx = a[0][0] , bigx = a[0][0];
	int smly = a[0][1] , bigy = a[0][1];
	REP(i , 0 , 4){
		smlx = min(smlx , a[i][0]);
		bigx = max(bigx , a[i][0]);

		smly = min(smly , a[i][1]);
		bigy = max(bigy , a[i][1]);
	}
	REP(i , 0 , 4){
		int x = b[i][0] , y = b[i][1];
		b[i][0] = x + y;
		b[i][1] = x - y;
	}
	REP(i , smlx , bigx + 1) REP(j , smly , bigy + 1) solve(i + j , i - j);

	cout << "NO" << endl;
    return 0;
}