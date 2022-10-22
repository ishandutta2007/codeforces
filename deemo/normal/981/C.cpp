#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n;
vector<int> adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (n == 2){
		cout << "Yes\n";
		cout << "1\n";
		cout << "1 2\n";
	}
	else{
		int mx = -1, root = -1;
		for (int i = 0; i < n; i++)
			if ((int)adj[i].size() > mx){
				root = i;
				mx = adj[i].size();
			}
		for (int i = 0; i < n; i++)
			if (i!=root && (int)adj[i].size() > 2){
				cout << "No\n";
				return 0;
			}
		cout << "Yes\n";
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if ((int)adj[i].size() == 1)
				cnt++;
		cout << cnt << "\n";
		for (int i = 0; i < n; i++)
			if ((int)adj[i].size() == 1)
				cout << root+1 << " " << i+1 << "\n";
	}
	return 0;
}