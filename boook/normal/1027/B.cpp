/*input
5 4
2 1
4 2
3 3
3 4
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
#define MAX 
#define INF 0x3f3f3f3f

int n , q;
// int query(int l , int r){
// 	return (l + r) * (r - l + 1) / 2;
// }
int32_t main(){
	IOS;
	cin >> n >> q;
	REP(i , 1 , q + 1){
		int a , b;
		cin >> a >> b;
		if((a + b) % 2 == 0){
			int line = (a - 1) / 2;
			int val = line * n;
			a -= line * 2;
			if(a == 1){
				val += (b + 1) / 2;
			}
			else {
				val += (n + 1) / 2;
				val += (b + 1) / 2;
			}
			cout << val << endl;
		}
		else {
			int val = (n * n + 1) / 2;
			int line = (a - 1) / 2;
			val += line * n;
			a -= line * 2;
			// DBGG("val = " , val);
			// DBGG(a , b);
			if(a == 1){
				val += (b + 1) / 2;
			}
			if(a == 2){
				val += n / 2;
				val += (b + 1) / 2;
			}
			cout << val << endl;
		}
	}
    return 0;
}