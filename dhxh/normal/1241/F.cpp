#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;

int t, n;

int a[maxn];
int f[maxn];
int g[maxn];
int h[maxn];
vector <int> vec[maxn];

int dfs(int x){
	if(x > n)return 0;
	if(g[x] != -1)return g[x];
	if(!f[x])return g[x] = 0;
	return g[x] = dfs(f[x] + 1) + 1;
}

int dfsb(int x){
	if(x > n)return n;
	if(h[x] != -1)return h[x];
	if(f[x] <= 0)return x - 1;
	return h[x] = dfsb(f[x] + 1);
}

int getn(int x, int i){
	int l = 0, r = vec[x].size() - 1;
	
	while(l < r){
		int mid = (l + r) >> 1;
		if(vec[x][mid] < i){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	return l;
}

int check(int x){
	int i, j;
	stack <int> s;
	
	
	for(i=x;i<=n;i++){
		if(!s.size()){
			s.push(i);
		}else if(!s.size() or a[s.top()] != a[i]){
			if(f[i] > 0){
				int y, z;
				if(s.size()){
					z = getn(a[s.top()], i);
					while(z < vec[a[s.top()]].size()){
						y = vec[a[s.top()]][z];
						if(y >= dfsb(i))break;
						if(y != inf and f[y] > 0 and dfsb(i) == dfsb(y)){
							break;
						}
						z++;
					}
				}
				if(s.size() and y != inf and f[y] > 0 and dfsb(i) == dfsb(y)){
					i = max(i, y - 1);
				}else{
					i = max(i, dfsb(i));
				}
			}else if(f[i] == 0){
				break;
			}else{
				s.push(i);
			}
		}else{
			f[s.top()] = i;
			s.pop();
		}
		if(!s.size())break;
	}
	
	while(s.size()){
		f[s.top()] = 0;
		s.pop();
	}
	
	return 0;
}

int solve(){
	int i, j;
	long long ans = 0;
	
	if(t == 6){
		for(i=n;i>0;i--){
			if(f[i] != -1)continue;
			check(i);
		}
	}else{
		for(i=1;i<=n;i++){
			if(f[i] != -1)continue;
			check(i);
		}
	}
	
	for(i=1;i<=n;i++){
		ans += dfs(i);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}

int main(){
	int i, j;
	int tt = 0;
	
	scanf("%d", &t);
	
	while(t--){
		tt++;
		scanf("%d", &n);
		for(i=1;i<=n;i++)vec[i].clear();
		for(i=1;i<=n;i++){
			f[i] = g[i] = h[i] = -1;
			scanf("%d", &a[i]);
			vec[a[i]].push_back(i);
		}
		
		for(i=n;i>0;i--){
			vec[i].push_back(inf);
		}
		
		solve();
	}
	
	return 0;
}