#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 9;

const int MAXN = 1e5 + 10;

int n, m, par[MAXN];;

int get_par(int v){return par[v]==v?v:par[v]=get_par(par[v]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	iota(par, par + n, 0);
	int ans = 1;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		a = get_par(a), b = get_par(b);
		if (a == b)
			ans = (ans * 2) % MOD;
		else
			par[a] = b;
		printf("%d\n", (ans + MOD - 1) % MOD);
	}
	return 0;
}