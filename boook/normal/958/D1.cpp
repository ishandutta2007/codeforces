/*input
4
(99+98)/97
(26+4)/10
(12+33)/15
(5+1)/7
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n;
PII x[MAX];
map<PII , int> cc;
int rit(){
	char c = getchar();
	int res = 0;
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = res * 10 + c - '0' , c = getchar();
	return res;
}
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1){
		int a = rit() , b = rit() , c = rit();
		// scanf("(%d+%d)/%d" , &a , &b , &c);
		a += b;
		// cout << a << " " << b << " " << c << endl;
		int tmp = __gcd(a , c); 
		a /= tmp , c /= tmp;
		cc[mp(a , c)] ++;
		x[i] = mp(a , c);
		// DBGG(a , c);
	}
	REP(i , 1 , n + 1) cout << cc[x[i]] << " "; cout << endl;
    return 0;
}