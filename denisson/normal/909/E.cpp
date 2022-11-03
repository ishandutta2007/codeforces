#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

int n, m;
int type[100007];
vector<int> g[100007];
int cnt[100007];
int ans = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> type[i];
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[b].pub(a);
		cnt[a]++;
	}
	set<int> se[2];
	for (int i = 0; i < n; i++) if (cnt[i] == 0) se[type[i]].insert(i);
	while(1){
		if (max(se[0].size(), se[1].size()) == 0) break;
		
		while(se[0].size()){
			auto v = *(se[0].begin());
			se[0].erase(se[0].begin());
			for (int to : g[v]){
				cnt[to]--;
				if (cnt[to] == 0) se[type[to]].insert(to);
			}
		}

		if (se[1].size()) ans++;

		while(se[1].size()){
			auto v = *(se[1].begin());
			se[1].erase(se[1].begin());
			for (int to : g[v]){
				cnt[to]--;
				if (cnt[to] == 0) se[type[to]].insert(to);
			}
		}
	}
	cout << ans;
}