/*input
5 3 6
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

int a , b , c;
int32_t main(){
	IOS;
	cin >> a >> b >> c;
	int now = (a < b);
	string s;
	if(now == 0) s += "0" , a --;
	else         s += "1" , b --;
	now = 1 - now;
	REP(i , 1 , c + 1){
		if(now == 0) s += "0" , a --;
		else         s += "1" , b --;
		now = 1 - now;
	}
	REP(i , 0 , s.size()){
		cout << s[i];
		while(s[i] == '0' && a != 0) cout << '0' , a --;
		while(s[i] == '1' && b != 0) cout << '1' , b --;
	}
	cout << endl;
    return 0;
}