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
#define M 1000000007

const int N = 300000;
int n, x, A[N + 1], S[N + 1], AA[N + 1], T[N + 1], C[N + 1], ans;
vector<int> g[N + 1], cnt[N + 1];
bool isp[N + 1];

void pre(){
	for(int i = 2; i <= N; i++)
		if(!g[i].size()){
			isp[i] = 1;
			for(int j = i; j <= N; j += i)
				g[j].pb(i);
		}
}

int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	A[0] = T[0] = 1;
	for(int i = 1; i <= n; i++) A[i] = (ll)A[i - 1] * i % M, T[i] = (ll)T[i - 1] * 2 % M;
	AA[n] = pow(A[n], M - 2);
	for(int i = n - 1; i >= 0; i--) AA[i] = (ll)AA[i + 1] * (i + 1) % M;
	S[0] = C[0] = 1;
	for(int i = 1; i <= n; i++) C[i] = (ll)A[n] * AA[n - i] % M * AA[i] % M, (S[i] = S[i - 1] + C[i]) %= M;
	pre();
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		int y = x;
		for(auto v : g[x]){
			int num = 0;
			while(y % v == 0) y /= v, num++;
			cnt[v].pb(num);
		}
	}
	for(int i = 2; i <= N; i++)
		if(isp[i]){
			int cal = n - cnt[i].size();
			sort(all(cnt[i]));
			for(int j = 0; j < cnt[i].size(); j++)
				(ans += (ll)(M - T[n - 1] + S[j + cal]) * cnt[i][j] % M) %= M;
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