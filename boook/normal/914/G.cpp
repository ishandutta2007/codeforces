/*input
10
1 3 0 7 3 7 6 5 7 5
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
#define MAX 1000090
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define dv2 500000004LL

void FWTA(int x[MAX] , int l , int r){
    if(l == r) return;
    int m = ((l + r) >> 1) + 1;
    FWTA(x , l , m - 1) , FWTA(x , m , r);
    REP(i , 0 , m - l){
        int q = x[l + i] , w = x[m + i];
        x[l + i] = (q + w) % mod;
        x[m + i] = (q - w + mod) % mod;
    }
}
 void IFWTA(int x[MAX] , int l , int r){
    if(l == r) return;
    int m = ((l + r) >> 1) + 1;
    REP(i , 0 , m - l){
        int q = x[l + i] , w = x[m + i];
        x[l + i] = (q + w) * dv2 % mod;
        x[m + i] = (q - w + mod) * dv2 % mod;
    }
    IFWTA(x , l , m - 1) , IFWTA(x , m , r);
}

void FWTB(int x[MAX] , int l , int r){
    if(l == r) return;
    int m = ((l + r) >> 1) + 1;
    FWTB(x , l , m - 1) , FWTB(x , m , r);
    REP(i , 0 , m - l){
        int q = x[l + i] , w = x[m + i];
        x[l + i] = (q + w) % mod;
        x[m + i] = w % mod;
    }
}
 void IFWTB(int x[MAX] , int l , int r){
    if(l == r) return;
    int m = ((l + r) >> 1) + 1;
    REP(i , 0 , m - l){
        int q = x[l + i] , w = x[m + i];
        x[l + i] = (q - w + mod) % mod;
        x[m + i] = w % mod;
    }
    IFWTB(x , l , m - 1) , IFWTB(x , m , r);
}


void FWTC(int x[MAX] , int l , int r){
    if(l == r) return;
    int m = ((l + r) >> 1) + 1;
    FWTC(x , l , m - 1) , FWTC(x , m , r);
    REP(i , 0 , m - l){
        int q = x[l + i] , w = x[m + i];
        x[l + i] = q % mod;
        x[m + i] = (q + w) % mod;
    }
}
 void IFWTC(int x[MAX] , int l , int r){
    if(l == r) return;
    int m = ((l + r) >> 1) + 1;
    REP(i , 0 , m - l){
        int q = x[l + i] , w = x[m + i];
        x[l + i] = q % mod;
        x[m + i] = (w - q + mod) % mod;
    }
    IFWTC(x , l , m - 1) , IFWTC(x , m , r);
}

int n , x[MAX] , f[MAX] , a[MAX] , b[MAX] , c[MAX];
int32_t main(){
	IOS;
	cin >> n;
	f[1] = 1;
	REP(i , 2 , MAX) f[i] = (f[i - 1] + f[i - 2]) % mod;
	REP(i , 1 , n + 1){
		int in; cin >> in;
		x[in] ++;
	}
	int N = (1 << 17);

	REP(i , 0 , N) b[i] = c[i] = x[i];


	// FWTC(a , 0 , N - 1);
	// REP(i , 0 , N) a[i] = (a[i] * a[i]) % mod;
	// IFWTC(a , 0 , N - 1);
	REP(i , 0 , N){
		int ii = i;
		while(1){
			a[i] = (a[i] + x[ii] * x[i ^ ii]) % mod;
			if(ii == 0) break;
			else ii = (ii - 1) & i;
		}
	}

	FWTA(c , 0 , N - 1);
	REP(i , 0 , N) c[i] = (c[i] * c[i]) % mod;
	IFWTA(c , 0 , N - 1);
	

	// a[1] = 0;
	// a[2] = 0;
	// REP(i , 0 , N) cout << x[i] << " " ; cout << endl;
	// REP(i , 0 , N) cout << a[i] << " " ; cout << endl;
	// REP(i , 0 , N) cout << b[i] << " " ; cout << endl;
	// REP(i , 0 , N) cout << c[i] << " " ; cout << endl;
	REP(i , 0 , N) a[i] = a[i] * f[i] % mod;
	REP(i , 0 , N) b[i] = b[i] * f[i] % mod;
	REP(i , 0 , N) c[i] = c[i] * f[i] % mod;

	// int ans = 0;
	// set<int> cc;
	// REP(i , 0 , 20) cc.insert(1 << i);
	// REP(i , 0 , N) REP(j , 0 , N){
	// 	REP(k , 0 , N){
	// 		if(cc.find(i & j & k) != cc.end()){
	// 			ans = (ans + a[i] * b[j] * c[k]) % mod;
	// 		}
	// 	}
	// }
	// cout << ans << endl;

	FWTB(a , 0 , N - 1);
	FWTB(b , 0 , N - 1);
	FWTB(c , 0 , N - 1);

	REP(i , 0 , (1 << 17)) x[i] = a[i] * b[i] % mod * c[i] % mod;
	IFWTB(x , 0 , N - 1);

	int ans = 0;
	REP(i , 0 , 17 + 2) ans = (ans + x[1 << i]) % mod;
	cout << ans << endl;
    return 0;
}