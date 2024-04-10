/*input
9 3
1-h 1-e 2-l 1-o 1-w 1-o 1-r 1-l 1-d
2-l 1-o 1-w
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define AC 10430579
#define BC  1000000007LL
#define mod 1000000009LL

int n , m , apo = 0 , bpo = 0 , h[MAX] , pre[MAX];
PII a[MAX] , b[MAX];
int32_t main(){
	scanf("%lld%lld" , &n , &m);
	REP(i , 1 , n + 1){
		int cnt; char c;
		scanf("%lld-%c" , &cnt , &c);
		if(apo && c - 'a' == a[apo - 1].B) a[apo - 1].A += cnt;
		else a[apo ++] = mp(cnt , c - 'a');
	}
	REP(i , 1 , m + 1){
		int cnt; char c;
		scanf("%lld-%c" , &cnt , &c);
		if(bpo && c - 'a' == b[bpo - 1].B) b[bpo - 1].A += cnt;
		else b[bpo ++] = mp(cnt , c - 'a');
	}

	// DB4("apo = " , apo , "bpo = " , bpo);
	// REP(i , 0 , apo) cout << a[i].A << " "; cout << endl;
	// REP(i , 0 , bpo) cout << b[i].A << " "; cout << endl;

	int ans = 0;
	if(bpo == 1){
		REP(i , 0 , apo){
			if(a[i].B == b[0].B) ans += max(0LL , a[i].A - b[0].A + 1);
		}
	}
	else if(bpo == 2){
		REP(i , 1 , apo){
			if(a[i - 1].B == b[0].B && a[i].B == b[1].B){
				if(a[i - 1].A >= b[0].A && a[i].A >= b[1].A){
					ans ++;
				}
			}
		}
	}
	else {
		h[0] = 1;
		REP(i , 1 , MAX) h[i] = h[i - 1] * AC % mod;

		int val = 0;
		REP(i , 1 , bpo - 1){
			int tmp = (b[i].A * BC + b[i].B) % mod;
			val = (val + tmp * h[i]) % mod;
		}

		REP(i , 1 , apo - 1){
			int tmp = (a[i].A * BC + a[i].B) % mod;
			pre[i] = (pre[i - 1] + tmp * h[i]) % mod;
		}

		REP(i , bpo - 2 , apo - 1){
			int v1 = (pre[i] + mod - pre[i - bpo + 2]) % mod;
			int v2 = (val * h[i - bpo + 2]) % mod;
			// if(v1 == v2){
			// 	DB4("here = " , i , i - bpo + 2 , i + 1);
			// }
			if(v1 == v2 && a[i - bpo + 2].B == b[0].B && a[i + 1].B == b[bpo - 1].B){
				if(a[i - bpo + 2].A >= b[0].A && a[i + 1].A >= b[bpo - 1].A){
					ans ++;
				}
			}
		}
	}

	printf("%lld\n", ans);
    return 0;
}