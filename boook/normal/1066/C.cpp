/*input
10
L 100
R 100000
R 123
L 101
? 123
L 10
R 115
? 100
R 110
? 115
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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

map<int , int> cc;
int sml = 1 , big = 1;
int n;
string s;
int32_t main(){
	IOS;
	cin >> n;
	int idx;
	cin >> s >> idx;
	cc[idx] = 1;
	REP(i , 2 , n + 1){
		cin >> s >> idx;
		if(s == "L"){
			cc[idx] = sml - 1;
			sml --;
		}
		if(s == "R"){
			cc[idx] = big + 1;
			big ++;
		}
		if(s == "?"){
			int tmp = cc[idx];
			cout << min(tmp - sml , big - tmp) << endl;
		}
	}
    return 0;
}