#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 100;

int n, m, aa, bb, x, y;
vector<int>	adj[MAXN], f, g, sec;
bool found;
bool mark[MAXN], m1[MAXN], m2[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int v = 0; !found && v < n; v++)
		for (int u:adj[v]){
			if (found)	break;
			if ((int)adj[v].size() - 1 < x || (int)adj[u].size() - 1 < y)	continue;
			
			if ((int)adj[v].size() - 1 >= x + y){
				found = 1;
				int c = 0;
				for (int i = 0; c < y; i++)
					if (adj[u][i] != v){
						g.push_back(adj[u][i]);
						mark[adj[u][i]] = 1;
						c++;
					}

				c = 0;
				for (int i = 0; c < x; i++)
					if (adj[v][i] != u && !mark[adj[v][i]]){
						f.push_back(adj[v][i]);
						mark[adj[v][i]] = 1;
						c++;
					}
				aa = v, bb = u;
				break;
			}
			else if ((int)adj[u].size() - 1 >= x + y){
				found = 1;
				int c = 0;
				for (int i = 0; c < x; i++)
					if (adj[v][i] != u){
						f.push_back(adj[v][i]);
						mark[adj[v][i]] = 1;
						c++;
					}	
				
				c = 0;
				for (int i = 0; c < y; i++)
					if (adj[u][i] != v && !mark[adj[u][i]]){
						g.push_back(adj[u][i]);
						mark[adj[u][i]] = 1;
						c++;
					}
				aa = v, bb = u;
				break;
			}
			else{
				sec.clear();

				int c1 = 0, c2 = 0, c3 = 0;
				for (int a:adj[v]){
					if (a == u)	continue;
					m1[a] = 1, c1++;
					sec.push_back(a);
				}

				for (int b:adj[u]){
					if (b == v)	continue;
					m2[b] = 1;
					if (m1[b])
						c1--, c3++;
					else	c2++;
					sec.push_back(b);
				}

				if (c1 + c2 + c3 < x + y){
					for (int v:sec)
						m1[v] = m2[v] = 0;
					continue;
				}
				found = 1;
				aa = v, bb = u;

				for (int i = 0; x && i < (int)sec.size(); i++){
					if (m1[sec[i]] == 0 || m2[sec[i]])	continue;
					m1[sec[i]] = 0;
					f.push_back(sec[i]);
					x--;
				}
				for (int i = 0; y && i < (int)sec.size(); i++){
					if (!m2[sec[i]] || m1[sec[i]])	continue;
					m2[sec[i]] = 0;
					g.push_back(sec[i]);
					y--;
				}
				for (int i = 0; x; i++){
					if (m1[sec[i]] == 0)	continue;
					m1[sec[i]] = m2[sec[i]] = 0;
					f.push_back(sec[i]);
					x--;
				}

				for (int i = 0; y; i++){
					if (m2[sec[i]] == 0)	continue;
					m2[sec[i]] = m1[sec[i]] = 0;
					f.push_back(sec[i]);
					y--;
				}
				break;
			}
		}
	if (!found)
		cout << "NO\n";
	else{
		cout << "YES\n";
		cout << aa + 1 << " " << bb + 1 << "\n";
		for (int v:f)
			cout << v + 1 << " ";
		cout << endl;
		for (int u:g)
			cout << u + 1 << " ";
		cout << endl;
	}	
	return 0;
}