#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, t;

vector <int> e[maxn];
vector <int> w[maxn];

long long f[maxn][2];

bool cmp(long long x, long long y){
	return x > y;
}

int dfs(int x, int fa){
	int y, z;
	vector <long long> vec;
	
	for(int i=0;i<e[x].size();i++){
		y = e[x][i];
		z = w[x][i];
		if(y == fa)continue;
		dfs(y, x);
		f[x][0] += f[y][1];
		vec.push_back(f[y][0] + z - f[y][1]);
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	for(int i=0;i<vec.size();i++){
		if(vec[i] <= 0)break;
		if(i < m - 1){
			f[x][0] += vec[i];
		}else{
			f[x][1] = f[x][0] + vec[i];
			break;
		}
	}
	
	f[x][1] = max(f[x][1], f[x][0]);
	
	return 0;
}

int main(){
	int i, j;
	int x, y, z;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(i=1;i<=n;i++)e[i].clear(), w[i].clear(), f[i][0] = f[i][1] = 0;
		
		for(i=1;i<n;i++){
			scanf("%d%d%d", &x, &y, &z);
			e[x].push_back(y);
			w[x].push_back(z);
			e[y].push_back(x);
			w[y].push_back(z);
		}
		
		dfs(1, -1);
		
		printf("%lld\n", max(f[1][0], f[1][1]));
	}
	
	return 0;
}