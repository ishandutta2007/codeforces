#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 100;

int n;
vector<int>	adj[MAXN], ans;
bool mark[MAXN], found;

void gen(int rem){
	if (rem == 0){
		for (int i = 0; i < n; i++){
			int fl = 0;
			for (int u:adj[ans[i]])
				if (u == ans[(i + 1) % n] || u == ans[(i + 2) % n])
					fl++;
			if (fl != 2)
				return;
		}
		for (int u:ans)
			cout << u << " ";
		cout << endl;
		found = 1;
		return;
	}

	for (int i = 1; i <= n; i++){
		if (mark[i])	continue;
		ans.push_back(i);
		mark[i] = 1;
		gen(rem - 1);
		if (found)	return;
		mark[i] = 0;
		ans.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n; i++){
		int a, b;	cin >> a >> b;	
		adj[a].push_back(b);
		adj[b].push_back(a);
	}		
	bool everything_is_awesome = 1;
	for (int i = 1; i <= n; i++)
		if ((int)adj[i].size() != 4)	everything_is_awesome = 0;
	if (!everything_is_awesome){
		cout << -1 << endl;
		return	0;
	}

	if (n < 7){
		gen(n);
		if (!found)
			cout << -1 << endl;
		return	0;
	}
	
	for (int jj = 0; jj < 6; jj++){
		fill(mark, mark + MAXN, 0);
		ans.clear();
		ans.push_back(1);
		mark[1] = 1;
		int cnt = 0;

		for (int i = 0; i < n - 2; i++){
			int temp = ans.size();
			if (i == 0){
				bool fl = 0;
				for (int u:adj[1]){
					for (int v:adj[u]){
						if (u == 1)	continue;
						for (int xx:adj[v])
							if (xx == 1){
								cnt++;
								if (cnt - 1 < jj)	continue;
								ans.push_back(u);
								ans.push_back(v);
								mark[v] = mark[u] = 1;
								fl = 1;
								break;
							}
						if (fl)	break;
					}
					if (fl)	break;
				}
			}
			else{
				int v = ans[(int)ans.size() - 2], u = ans.back();
				bool fl = 0;
				for (int x:adj[v]){
					for (int y:adj[u])
						if (x == y && !mark[x]){
							cnt++;
							ans.push_back(x);
							mark[x] = 1;
							fl = 1;
							break;
						}
					if (fl)	break;
				}	
			}
			if (temp == (int)ans.size())	break;
		}	
		if ((int)ans.size() != n)	continue;

		int fl = 0;
		for (int i = 0; i < n; i++){
			fl = 0;
			for (int u:adj[ans[i]])
				if (u == ans[(i + 1) % n] || u == ans[(i + 2) % n])		
					fl++;

			if (fl != 2)	break;
		}
		if (fl == 2){
			for (int u:ans)
				cout << u << " ";
			cout << endl;
			return	0;
		}	
	}
	cout << -1 << endl;
	return 0;
}