#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 5;
ll n, m;
ll x[maxn], y[maxn], c[maxn];
vector<ll> v[maxn];
vector<ll> g[maxn];
ll p[maxn];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> x[i] >> y[i];
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		v[c[i]].push_back(i);
	}
	for(int i = 1;i <= m;i++){
		if(c[x[i]] == c[y[i]]){
			puts("-1");
			return 0;
		}
	}
	for(int i = 1;i <= n;i++){
		for(auto j : v[i]){
			vector<ll> col;
			for(auto k : g[j]){
				if(p[k] == 0) continue;
				col.push_back(p[k]);
			}
			sort(col.begin(), col.end());
			ll tmp = 0;
			for(auto k : col){
				if(k - tmp == 1 || k - tmp == 0){
					tmp = k;
				} else {
					break;
				}
			}
			tmp++;
			if(tmp == i){
				p[j] = i;
			} else {
				puts("-1");
				return 0;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(auto j : v[i]){
			cout << j << " ";
		}
	}
	puts("");
	return 0;
}