#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, k, t;

struct ex {
	int y;
	int w;
};

vector <ex> e[maxn];

bool v[105][105];
bool f[maxn];
vector <pair <int, int> > vec[maxn];
int ans = 0;
int sum = 0;
int cnt[105];

int a[105];

int getn(int x, int y){
	return (x - 1) * 10 + y;
}

bool cmp(ex A, ex B){
	return A.w < B.w;
}

int dfs(int x){
	if(x == k + 1){
		ans++;
		return 0;
	}
	
	for(int i=1;i<=x;i++){
		if(f[getn(x, i)]) continue;
		bool flag = false;
		for(int j=1;j<x;j++){
			if(v[getn(j, a[j])][getn(x, i)]) flag = true;
		}
		if(flag) continue;
		a[x] = i;
		sum += cnt[getn(x, i)];
		dfs(x + 1);
		sum -= cnt[getn(x, i)];
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y, w;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(i=1;i<=m;i++){
		scanf("%d%d%d", &x, &y, &w);
		e[x].push_back({y, w});
	}
	
	for(i=1;i<=n;i++){
		sort(e[i].begin(), e[i].end(), cmp);
		for(j=0;j<e[i].size();j++){
			int y = e[i][j].y;
			vec[y].push_back({e[i].size(), j + 1});
			cnt[getn(e[i].size(), j + 1)]++;
		}
	}
	
	for(x=1;x<=n;x++){
		sort(vec[x].begin(), vec[x].end());
		for(i=1;i<vec[x].size();i++){
			if(vec[x][i] == vec[x][i - 1]){
				f[getn(vec[x][i].first, vec[x][i].second)] = true;
			}
		}
		
		int sz = unique(vec[x].begin(),vec[x].end()) - vec[x].begin();
		vec[x].resize(sz);
		for(i=0;i<sz;i++){
			for(j=i+1;j<sz;j++){
				v[getn(vec[x][i].first, vec[x][i].second)][getn(vec[x][j].first, vec[x][j].second)] = true;
				v[getn(vec[x][j].first, vec[x][j].second)][getn(vec[x][i].first, vec[x][i].second)] = true;
			}
		}
	}
	
	dfs(1);
	
	printf("%d\n", ans);
	
	return 0;
}