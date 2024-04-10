/*input
3 27
432121414121412121414121212
214343232343234343232343434
432121414121412121414121212
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , ok , x[MAX][MAX];
string s[MAX];
void Print(){
	REP(i , 0 , n){
		REP(j , 0 , m) cout << x[i][j] ; cout << endl;
	}
	exit(0);
}
void solve1(int a , int b , int c , int d){
	REP(i , 0 , n){
		int v1 , v2 , ok1 = 1 , ok2 = 1;
		if(i % 2 == 0) v1 = a , v2 = b;
		if(i % 2 == 1) v1 = c , v2 = d;
		REP(j , 0 , m){
			if(s[i][j] != '0' && j % 2 == 0 && s[i][j] - '0' != v1) ok1 = 0;
			if(s[i][j] != '0' && j % 2 == 1 && s[i][j] - '0' != v2) ok1 = 0;

			if(s[i][j] != '0' && j % 2 == 0 && s[i][j] - '0' != v2) ok2 = 0;
			if(s[i][j] != '0' && j % 2 == 1 && s[i][j] - '0' != v1) ok2 = 0;
		}
		if(!ok1 && !ok2) return;
		else if(ok1) x[i][0] = v1 , x[i][1] = v2;
		else if(ok2) x[i][0] = v2 , x[i][1] = v1;
	}
	REP(i , 0 , n) REP(j , 2 , m) x[i][j] = x[i][j - 2];
	Print();
}
void solve2(int a , int b , int c , int d){
	REP(j , 0 , m){
		int v1 , v2 , ok1 = 1 , ok2 = 1;
		if(j % 2 == 0) v1 = a , v2 = b;
		if(j % 2 == 1) v1 = c , v2 = d;
		REP(i , 0 , n){
			if(s[i][j] != '0' && i % 2 == 0 && s[i][j] - '0' != v1) ok1 = 0;
			if(s[i][j] != '0' && i % 2 == 1 && s[i][j] - '0' != v2) ok1 = 0;

			if(s[i][j] != '0' && i % 2 == 0 && s[i][j] - '0' != v2) ok2 = 0;
			if(s[i][j] != '0' && i % 2 == 1 && s[i][j] - '0' != v1) ok2 = 0;
		}
		if(!ok1 && !ok2) return;
		else if(ok1) x[0][j] = v1 , x[1][j] = v2;
		else if(ok2) x[0][j] = v2 , x[1][j] = v1;
	}
	REP(i , 2 , n) REP(j , 0 , m) x[i][j] = x[i - 2][j];
	Print();
}
void solve(int a , int b , int c , int d){
	solve1(a , b , c , d);
	solve2(a , b , c , d);
}
int32_t main(){
	IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];

    solve(1 , 2 , 3 , 4);
    solve(1 , 3 , 2 , 4);
    solve(1 , 4 , 2 , 3);
    solve(2 , 3 , 1 , 4);
    solve(2 , 4 , 1 , 3);
    solve(3 , 4 , 1 , 2);
    cout << 0 << endl;
    return 0;
}