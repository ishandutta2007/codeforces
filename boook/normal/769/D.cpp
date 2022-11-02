/*input
3 2
0 3 3
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
#define MAX 20000
#define INF 0x3f3f3f3f

int n , m , x[MAX] , one[MAX];
inline int rit(){
	char c = getchar();
	int res = 0;
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		res = (res << 1) + (res << 3) + c - '0';
		c = getchar();
	}
	return res;
}
int32_t main(){
	n = rit() , m = rit();
	REP(i , 1 , n + 1) x[rit()] ++;
	REP(i , 1 , (1 << 14)){
		if(i & 1) one[i] = one[i >> 1] + 1;
		else one[i] = one[i >> 1];
	}
	long long ans = 0;
	REP(i , 0 , (1 << 14)){
		if(x[i]){
			REP(j , i + 1 , (1 << 14)){
				if(one[i ^ j] == m){
					ans += 1LL * x[i] * x[j];
				}
			}
			if(m == 0) ans += 1LL * x[i] * (x[i] - 1) / 2;
		}
	}
	printf("%lld\n", ans);
    return 0;
}