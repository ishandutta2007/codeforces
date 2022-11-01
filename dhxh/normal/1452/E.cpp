#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 5;

int n, m, k;

struct ex {
	int l, r;
} a[maxn];

vector <int> A[maxn];

vector <int> L[maxn];
vector <int> R[maxn];

bool vis[maxn];

int main(){
	int i, j;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(i=1;i<=m;i++){
		scanf("%d%d", &a[i].l, &a[i].r);
		L[a[i].l].push_back(i);
		R[a[i].r].push_back(i);
	}
	
	int ans = 0;
	
	for(i=k;i<=n;i++){
		int l = i - k + 1, r = i;
		int sum = 0;
		for(j=0;j<=n;j++){
			A[j].clear();
		}
		
		for(j=1;j<=m;j++){
			int s = max(min(a[j].r, r) - max(a[j].l, l) + 1, 0);
			sum += s;
			if(s != a[j].r - a[j].l + 1 and s != r - l + 1) A[a[j].r - s].push_back(j);
		}
		
		memset(vis, 0, sizeof(vis));
		
		int x = n - k + 2, y = n + 1;
		int ca = 0, cb = 0;
		
		for(j=n;j>n-k+1;j--){
			for(auto k : A[j]){
				vis[k] = true;
				sum -= max(min(a[k].r, r) - max(a[k].l, l) + 1, 0);
				sum += max(min(a[k].r, y) - max(a[k].l, x) + 1, 0);
			}
		}
		
		for(j=n;j>n-k+1;j--){
			for(auto k : R[j]){
				if(vis[k]) ca++;
			}
			
			for(auto k : L[j]){
				if(vis[k]) ca--;
			}
		}
		
		for(j=n-k+1;j>=i-k+1;j--){
			x = j, y = j + k - 1;
			for(auto k : R[x]){
				if(vis[k]) ca++;
			}
			sum += ca;
			sum -= cb;
			
			for(auto k : A[j]){
				vis[k] = true;
				sum -= max(min(a[k].r, r) - max(a[k].l, l) + 1, 0);
				sum += max(min(a[k].r, y) - max(a[k].l, x) + 1, 0);
				ca++;
				if(a[k].r > y) cb++;
			}
			
			ans = max(ans, sum);
			
			for(auto k : R[y]){
				if(vis[k]) cb++;
			}
			
			for(auto k : L[y + 1]){
				if(vis[k]) cb--;
			}
			
			for(auto k : L[x]){
				if(vis[k]) ca--;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}