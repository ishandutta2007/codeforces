/*input
5
zcabd
dbacz
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

string a , b;
int32_t main(){
	IOS;
	cin >> a >> a >> b;
	int ans = 0;
	REP(i , 0 , a.size()){
		int v1 = i , v2 = a.size() - 1 - i;
		if(v1 > v2) break;
		if(v1 == v2){
			if(a[v1] != b[v1]) ans ++;
		}
		else {
			map<char , int> cc;
			cc[a[v1]] ++;
			cc[a[v2]] ++;
			cc[b[v1]] ++;
			cc[b[v2]] ++;
			if(cc.size() == 2){
				if(cc[a[v1]] % 2 == 1) ans ++;
			}
			else if(cc.size() == 3){
				ans ++;
				if(a[v1] == a[v2]) ans ++;
			}
			else if(cc.size() == 4) ans += 2;
		}
			// DBGG(i , ans);
	}
	cout << ans << endl;
    return 0;
}