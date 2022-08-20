#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

double ar[18][262144], beat[18][18];
bool done[18][262144];
ll des;
int n;

double dp(int cur, int used) {
	if (done[cur][used]) return ar[cur][used];
	double curans = 0;
	if (cur == 0) {
		if (used == des) return 1;
		F0R(i,n) if ((used & (1<<i)) == 0 && i != 0) {
			curans = max(curans,beat[0][i]*dp(0,used | (1<<i)));
		}
	} else {
		F0R(i,n) {
			if ((used & (1<<i)) == 0 && i != cur) {
				if (i == 0) curans = beat[0][cur]*dp(0,used | (1<<cur));
				else curans = max(curans,dp(cur,used | (1<<i))*beat[cur][i]+dp(i,used | (1<<cur))*beat[i][cur]);
			}
		}
	}
	done[cur][used] = 1, ar[cur][used] = curans;
	return curans;
}

int main() {
	ios_base::sync_with_stdio(0);
	double ans = 0;
	cin >> n;
	des = (ll)pow(2,n)-2;
	F0R(i,n) F0R(j,n) cin >> beat[i][j];
	F0R(i,n) ans = max(ans,dp(i,0));
	cout << fixed << setprecision(10) << ans;
}