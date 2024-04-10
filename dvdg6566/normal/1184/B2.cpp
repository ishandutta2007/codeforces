#include <bits/stdc++.h>
 
using namespace std;
int memo[200005];
struct ship{
	int x;
	int a;
	int f;
};
struct base{
	int x;
	int d;
};

vector<int> match, vis;
vector<int> adj[2005];

int Aug(int l){
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int j = 0;j < (int) adj[l].size();j++){
		int r = adj[l][j];
		if(match[r] == -1 || Aug(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}
int main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int gn, gm;
	cin >> gn >> gm;
	
	int mat[gn][gn];
	for(int i = 0;i < gn;i++){
		for(int j = 0;j < gn;j++){
			mat[i][j] = 102345678;
		}
	}
	
	for(int i = 0;i < gn;i++){
		mat[i][i] = 0;
	}
	
	for(int i = 0;i < gm;i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if(a == b) continue;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	
	for(int k = 0;k < gn;k++){
		for(int i = 0;i < gn;i++){
			for(int j = 0;j < gn;j++){
				mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
			}
		}
	}
	
	for(int i = 0;i < gn;i++){
		for(int j = 0;j < gn;j++){
			//cout << mat[i][j] << " ";
		}
		//cout << "\n";
	}
	
	long long n, m, k, h;
	cin >> n >> m >> k >> h;
	
	ship ships[n];
	base bases[m];
	
	for(int i = 0;i < n;i++){
		cin >> ships[i].x >> ships[i].a >> ships[i].f;
		ships[i].x--;
	}
	for(int i = 0;i < m;i++){
		cin >> bases[i].x;
		cin >> bases[i].d;
		bases[i].x--;
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			ship s = ships[i];
			base b = bases[j];
			if(s.f >= mat[s.x][b.x] && s.a >= b.d){
				adj[i].push_back(n+j);
			}
		}
	}
	
	long long MCBM = 0;
	int V = n + m;
	match.assign(V, -1);
	for(int l = 0;l < n;l++){
		vis.assign(n,0);
		MCBM += Aug(l);
	}
	
	//cout << MCBM << "\n";
	
	long long ans = k * MCBM;
	ans = min(ans, h * n);
	cout << ans;
	return 0;
}