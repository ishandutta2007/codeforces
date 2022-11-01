#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 5;
const int mod = 998244353;

int n;

pair <int, int> a[maxn];

int f[maxn][maxn];
int ans = 0;

bool cmp(int x, int y){
	return a[x].second < a[y].second or (a[x].second == a[y].second and x < y);
}

void solve(int p){
	int i, j;
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	
	for(i=1;i<=n;i++){
		if(i < p){
			for(j=0;j<=i;j++){
				f[i][j] = f[i - 1][j];
			}
			if(a[i].first){
				int x = cmp(i, p);
				for(j=0;j<=i;j++){
					f[i][j + x] += f[i - 1][j];
					if(f[i][j + x] >= mod) f[i][j + x] -= mod;
				}
			}else{
				for(j=1;j<=i;j++){
					f[i][j - 1] += f[i - 1][j];
					if(f[i][j - 1] >= mod) f[i][j - 1] -= mod;
				}
				f[i][0] += f[i - 1][0];
				if(f[i][0] >= mod) f[i][0] -= mod;
			}
		}else if(i == p){
			for(j=0;j<=i;j++){
				f[i][j] = f[i - 1][j];
			}
		}else{
			for(j=0;j<=i;j++){
				f[i][j] = f[i - 1][j];
			}
			if(a[i].first){
				int x = cmp(i, p);
				for(j=0;j<=i;j++){
					f[i][j + x] += f[i - 1][j];
					if(f[i][j + x] >= mod) f[i][j + x] -= mod;
				}
			}else{
				for(j=1;j<=i;j++){
					f[i][j - 1] += f[i - 1][j];
					if(f[i][j - 1] >= mod) f[i][j - 1] -= mod;
				}
			}
		}
	}
	
	for(i=0;i<=n;i++){
		ans = (ans + 1ll * f[n][i] * a[p].second) % mod;
	}
}

int main(){
	int i, j;
	char ch;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf(" %c", &ch);
		if(ch == '-'){
			a[i] = {0, 0};
		}else{
			scanf("%d", &x);
			a[i] = {1, x};
		}
	}
	
	for(i=1;i<=n;i++){
		if(a[i].first == 0) continue;
		solve(i);
	}
	
	printf("%d\n", ans);
	
	return 0;
}