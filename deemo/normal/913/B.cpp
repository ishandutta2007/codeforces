#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, cnt[MAXN];
vector<int> adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int p; cin >> p; p--;
		adj[p].push_back(i);
	}
	for (int i = n-1; ~i; i--){
		if (adj[i].empty())
			cnt[i] = 1;
		else{
			int c = 0;
			for (int u:adj[i])
				c += cnt[u];
			if (c < 3){
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}