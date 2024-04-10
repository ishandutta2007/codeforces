/*input
2 100
-10000
0
1
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
#define int long long
#define MAX 700000
#define INF 0x3f3f3f3f

inline PII rit(){
	char c = getchar();
	int tt = 1;
	while(!isdigit(c)){
		if(c == '?') return mp(INF , 1);
		if(c == '-') tt = -1;
		c = getchar();
	}
	int res = 0;
	while(isdigit(c)){
		res = (res << 1) + (res << 3) + c - '0';
		c = getchar();
	}
	return mp(res * tt , 0);
}
int n , m , x[MAX];
int32_t main(){
	cin >> n >> m;
	int cnt = 0;
	REP(i , 0 , n + 1){
		PII tmp = rit();
		x[i] = tmp.A;
		if(tmp.B) cnt ++;
	}
	if(m == 0){
		if(x[0] == INF){
			if((n + 1 - cnt) % 2 == 0) cout << "No" << endl;
			if((n + 1 - cnt) % 2 == 1) cout << "Yes" << endl;
		}
		else if(x[0] == 0) cout << "Yes" << endl;
		else if(x[0] != 0) cout << "No" << endl;
	}
	else {
		int m1 = 1000000007LL;
		int m2 = 10430579LL;
		int v1 = 0 , v2 = 0;
		if(cnt == 0){
			RREP(i , n , 0){
				v1 = v1 * m + x[i];
				v2 = v2 * m + x[i];
				v1 = (v1 % m1 + m1) % m1;
				v2 = (v2 % m2 + m2) % m2;
			}
			if(v1 == 0 && v2 == 0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else if(n % 2 == 0) cout << "No" << endl;
		else if(n % 2 == 1) cout << "Yes" << endl;
	}
    return 0;
}