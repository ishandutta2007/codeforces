#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

vector <int> e[maxn];

long long a[maxn];

int d[maxn];
int c[maxn];
bool f;

bool cmp(int x, int y){
	return d[x] > d[y];
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		for(i=1;i<=n;i++) e[i].clear(), c[i] = i, d[i] = -1;
		f = false;
		
		for(i=1;i<=n;i++) scanf("%lld", &a[i]);
		for(i=1;i<=n;i++){
			scanf("%d", &x);
			a[i] = x - a[i];
		}
		
		for(i=1;i<=m;i++){
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		
		queue <int> q;
		q.push(1);
		d[1] = 0;
		
		while(q.size()){
			int x = q.front();
			q.pop();
			for(auto y : e[x]){
				if(d[y] == -1){
					d[y] = d[x] + 1;
					q.push(y);
				}else{
					if(d[y] % 2 == d[x] % 2){
						f = true;
					}
				}
			}
		}
		
		sort(c + 1, c + n + 1, cmp);
		
		for(i=1;i<=n;i++){
			x = c[i];
			for(auto y : e[x]){
				if(d[y] == d[x] - 1){
					a[y] -= a[x];
					break;
				}
			}
		}
		
		if(!a[1] or (f and a[1] % 2 == 0)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}