//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }

const int M = 1e9 + 7, N = 1023;
int n, a[N][N];
double b[N][N];
char s[N];
int L[N][N], R[N][N], D[N][N], U[N][N], LU[N][N], LD[N][N], RU[N][N], RD[N][N];
ll l[N][N], r[N][N], d[N][N], u[N][N], lu[N][N], ld[N][N], ru[N][N], rd[N][N];
double tl[N][N], tr[N][N], td[N][N], tu[N][N], tlu[N][N], tld[N][N], tru[N][N], trd[N][N];
double tans; int ans;

inline int pow(ll a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s);
		for(int j = 1; j <= n; ++j){
			a[i][j] = s[j - 1] - '0';
			ans = max(a[i][j], ans);
			b[i][j] = log(a[i][j]);
		}
	}

	for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j <= n + 1; ++j){
			l[i][j] = r[i][j] = u[i][j] = d[i][j] = 1;
			lu[i][j] = ru[i][j] = ld[i][j] = rd[i][j] = 1;
		}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(a[i][j]) L[i][j] = L[i][j - 1] + 1, l[i][j] = l[i][j - 1] * a[i][j] % M, tl[i][j] = tl[i][j - 1] + b[i][j];
			if(a[i][j]) LU[i][j] = LU[i - 1][j - 1] + 1, lu[i][j] = lu[i - 1][j - 1] * a[i][j] % M, tlu[i][j] = tlu[i - 1][j - 1] + b[i][j];
		}
	}

	for(int i = n; i >= 1; --i){
		for(int j = n; j >= 1; --j){
			if(a[i][j]) R[i][j] = R[i][j + 1] + 1, r[i][j] = r[i][j + 1] * a[i][j] % M, tr[i][j] = tr[i][j + 1] + b[i][j];
			if(a[i][j]) RD[i][j] = RD[i + 1][j + 1] + 1, rd[i][j] = rd[i + 1][j + 1] * a[i][j] % M, trd[i][j] = trd[i + 1][j + 1] + b[i][j];
		}
	}
	
	for(int j = n; j >= 1; --j){
		for(int i = 1; i <= n; ++i){
			if(a[i][j]) U[i][j] = U[i - 1][j] + 1, u[i][j] = u[i - 1][j] * a[i][j] % M, tu[i][j] = tu[i - 1][j] + b[i][j];
			if(a[i][j]) RU[i][j] = RU[i - 1][j + 1] + 1, ru[i][j] = ru[i - 1][j + 1] * a[i][j] % M, tru[i][j] = tru[i - 1][j + 1] + b[i][j];
		}
	}

	for(int j = 1; j <= n; ++j){
		for(int i = n; i >= 1; --i){
			if(a[i][j]) D[i][j] = D[i + 1][j] + 1, d[i][j] = d[i + 1][j] * a[i][j] % M, td[i][j] = td[i + 1][j] + b[i][j];
			if(a[i][j]) LD[i][j] = LD[i + 1][j - 1] + 1, ld[i][j] = ld[i + 1][j - 1] * a[i][j] % M, tld[i][j] = tld[i + 1][j - 1] + b[i][j];
		}
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			if(!a[i][j]) continue;
			int dd = min(min(L[i][j], R[i][j]), min(U[i][j], D[i][j]));
			double tres = tl[i][j] + tr[i][j] + tu[i][j] + td[i][j] - tl[i][j - dd] - tr[i][j + dd] - tu[i - dd][j] -td[i + dd][j] - 3 * b[i][j];
			if(tres > tans){
				tans = tres;
				int t = pow((ll)a[i][j], M - 2);
				ll res = l[i][j] * r[i][j] % M * u[i][j] % M * d[i][j] % M;
				res = res * pow(l[i][j - dd], M - 2) % M;
				res = res * pow(r[i][j + dd], M - 2) % M;
				res = res * pow(u[i - dd][j], M - 2) % M;
				res = res * pow(d[i + dd][j], M - 2) % M;
				res = res * t % M * t % M * t % M;
				ans = res;
			}
			
			dd = min(min(LU[i][j], LD[i][j]), min(RU[i][j], RD[i][j]));

			tres = tlu[i][j] + tld[i][j] + tru[i][j] + trd[i][j] - tlu[i - dd][j - dd] - tld[i + dd][j - dd] - tru[i - dd][j + dd] - trd[i + dd][j + dd] - 3 * b[i][j];
			if(tres > tans){
				tans = tres;
				int t = pow((ll)a[i][j], M - 2);
				ll res = lu[i][j] * ld[i][j] % M * ru[i][j] % M * rd[i][j] % M;
				res = res * pow(lu[i - dd][j - dd], M - 2) % M;
				res = res * pow(ld[i + dd][j - dd], M - 2) % M;
				res = res * pow(ru[i - dd][j + dd], M - 2) % M;
				res = res * pow(rd[i + dd][j + dd], M - 2) % M;
				res = res * t % M * t % M * t % M;
				ans = res;
			}
		}
	cout << ans;
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/