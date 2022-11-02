/*input
3 5 2
aaa
baaab
1 3
1 1
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
#define MAX 100090
#define INF 0x3f3f3f3f

int n , m , k , v[MAX];
string a , b;
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	cin >> a >> b;
	REP(i , 0 , a.size()){
		string p = a.substr(i , b.size());
		if(p == b) v[i + 1] ++;
	}
	REP(i , 1 , a.size() + 1) v[i] += v[i - 1];

	REP(i , 1 , k + 1){
		int l , r;
		cin >> l >> r;
		if(r - l + 1 < b.size()) cout << 0 << endl;
		else {
			int rr = r - (int)b.size() + 1;
			// cout << rr << endl;
			cout << v[rr] - v[l - 1] << endl;
		}
	}
    return 0;
}