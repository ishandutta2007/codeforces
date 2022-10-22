#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;

int n, p[MAXN], pos[MAXN], cc[MAXN];
ll ans=0;
ll fen[MAXN];

void add(int v, ll x){for (v++; v<MAXN; v+=v&-v) fen[v]+=x;}
ll get(int v){ll ret = 0; for (; v; v-=v&-v) ret += fen[v]; return ret;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--, pos[p[i]] = i;

	for (int i = n - 1; ~i; i--){
		ans += ((get(MAXN - 1) - get(pos[i]))*(pos[i]+1));
		add(pos[i], n-pos[i]);
	}

	memset(fen, 0, sizeof(fen));
	for (int i = n - 1; ~i; i--){
		cc[i] = get(pos[i]);
		add(pos[i], 1);
	}

	memset(fen, 0, sizeof(fen));
	ll tot = 1ll*n*(n+1);
	ll temp = 0;
	for (int i = n - 1; ~i; i--){
		ans -= get(pos[i]) * (n-pos[i]);
		temp += cc[i];
		add(pos[i], pos[i]+1);
	}

	cout << ans/ld(tot)+temp << "\n";
	return 0;
}