#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<utility>
#include<Vector>
#include<cstring>

using namespace std;

const int MAXN = 1e4 + 200;

string ss[MAXN];
int sz;
vector<int>	adj[MAXN];
map<string, int>	mp;
bool mark[MAXN];
int cnt[MAXN], maxi[MAXN];
bool dd[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;	cin >> m;
	while (m--){
		string a, b;	cin >> a >> b;
		if (mp.count(a) == 0){
			mp[a] = sz;
			ss[sz++] = a;
		}
		if (mp.count(b) == 0){
			mp[b] = sz;
			ss[sz++] = b;
		}
		adj[mp[a]].push_back(mp[b]);
		adj[mp[b]].push_back(mp[a]);
		dd[mp[a]][mp[b]] = dd[mp[b]][mp[a]] = 1;
	}
	
	cout << sz << endl;
	for (int i = 0; i < sz; i++){
		memset(mark, 0, sizeof(mark));
		for (int u:adj[i])
			mark[u] = 1;
		for (int j = 0; j < sz; j++)
			if (i != j && !dd[i][j]){
				int c = 0;
				for (int u:adj[j])
					if (mark[u])	c++;
				if (c > maxi[i]){
					maxi[i] = c;
					cnt[i] = 1;
				}
				else if(c == maxi[i])	cnt[i]++;
			}
		cout << ss[i] << " " << cnt[i] << endl;
	}
	return 0;
}