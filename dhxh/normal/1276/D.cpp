#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int n;
vector <int> e[maxn];

long long f[maxn][5];
//0 for deleted (or not deleted) after this edge
//1 for deleted by son before this edge
//2 for deleted by father

void dfs(int x, int fa){
	if(e[x].size() == 1 and fa != -1){
		f[x][0] = f[x][2] = 1;
		return;
	}
	int p = (int)e[x].size();
	int i;
	vector <int> vec = {1};
	for(i=(int)e[x].size()-1;i>=0;i--){
		int y = e[x][i];
		if(y == fa){
			p = i;
			vec.push_back(vec.back());
			continue;
		}
		dfs(y, x);
		vec.push_back(vec.back() * (f[y][0] + f[y][1]) % mod);
	}
	
	vec.pop_back();
	reverse(vec.begin(), vec.end());
	long long sum = 1;
	for(i=0;i<p;i++){
		int y = e[x][i];
		f[x][1] = (f[x][1] + sum * f[y][0] % mod * vec[i]) % mod;
		sum = sum * (f[y][2] + f[y][1]) % mod;
	}
	f[x][2] = sum * vec[i] % mod;
	
	for(i=p+1;i<e[x].size();i++){
		int y = e[x][i];
		f[x][0] = (f[x][0] + sum * f[y][0] % mod * vec[i]) % mod;
		sum = sum * (f[y][2] + f[y][1]) % mod;
	}
	f[x][0] = (f[x][0] + sum) % mod;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	dfs(1, -1);
	
	printf("%lld\n", (f[1][0] + f[1][1]) % mod);
	
	return 0;
}