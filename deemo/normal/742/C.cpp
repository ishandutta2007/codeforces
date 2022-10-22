#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100 + 5;

int n, p[MAXN], cnt[MAXN];
bool vis[MAXN];
int cc = 0;
vector<ll>	vec;

void dfs(int v){
	vis[v] = 1;
	cc++;
	if (!vis[p[v]])
		dfs(p[v]);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i], p[i]--;
		if (cnt[p[i]]){
			cout << "-1\n";
			return 0;
		}
		cnt[p[i]]++;
	}
	for (int v = 0; v < n; v++)
		if (!vis[v]){
			cc=0;
			dfs(v);
			if (cc&1)
				vec.push_back(cc);
			else
				vec.push_back(cc>>1);
		}
	ll ans = vec[0];
	for (ll z:vec){
		ll g = __gcd(ans, z);
		ans *= z/g;
	}
	cout << ans << endl;
	return 0;
}