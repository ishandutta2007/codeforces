#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

int a[maxn];
int ans[maxn];
int ecnt[maxn];

bool vis[maxn];

int dfs(int x){
	int y = a[x];
	vis[x] = true;
	if(!y) return x;
	if(vis[y]) return -1;
	return dfs(y);
}

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		ans[i] = a[i];
		if(a[i]){
			ecnt[a[i]]++;
		}
	}
	
	vector <int> vec;
	
	for(i=1;i<=n;i++){
		if(vis[i] or ecnt[i]) continue;
		int x = dfs(i);
		if(x != -1){
			vec.push_back(i);
			vec.push_back(x);
		}
	}
	
	for(i=1;i<vec.size();i+=2){
		ans[vec[i]] = vec[(i + 1) % vec.size()];
	}
	
	for(i=1;i<=n;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}