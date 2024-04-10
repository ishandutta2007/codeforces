#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
 
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
ll n;
vector<vector<ll>> gr;
vector<ll> vec;
 
void input() {
	cin >> n;
	vec.resize(n);
	for (auto& c : vec) cin >> c;
 
	gr.resize(n);
 
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		u--; v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
}
 
ll sol() {
	ll ans = 0;
 
	set<pair<ll, ll>> leaves;
	vector<pair<ll, ll>> srt;
	vector<ll> degree(n);
 
	srt.push_back({ 0, -1 });
	for (int i = 0; i < n; i++) {
		degree[i] = gr[i].size();
 
		srt.push_back({ vec[i], i });
		if (gr[i].size() == 1) {
			leaves.insert({vec[i], i});
		}
	}
 
	sort(srt.begin(), srt.end());
 
	for (int i = 1; i <= n; i++) {
		while (leaves.size() > 0 && (*leaves.begin()).first < srt[i].first) {
			ll v = (*leaves.begin()).second;
			degree[v] = -2;
			leaves.erase(leaves.begin());
 
			for (auto to : gr[v]) {
				degree[to]--;
				if (degree[to] == 1 || degree[to] == 0) leaves.insert({ vec[to], to });
			}
		}
 
		ans += max(2ll, ll(leaves.size())) * (srt[i].first - srt[i - 1].first);
	}
 
	return ans;
}
 
int main() {
	fastInp;
 
	input();
	cout << sol();
 
	return 0;
}