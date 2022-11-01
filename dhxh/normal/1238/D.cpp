#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

string str;
int n;

int a[maxn];
int f[maxn];
int g[maxn];

int p[2];

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		char ch;
		scanf(" %c", &ch);
		a[i] = ch - 'A';
	}
	
	for(i=1;i<=n;i++){
		f[i] = p[a[i]];
		p[a[i]] = i;
	}
	
	p[0] = p[1] = n + 1;
	g[n + 1] = n + 1;
	
	for(i=n;i>0;i--){
		g[i] = p[a[i]];
		p[a[i]] = i;
	}
	
	long long ans = 1ll * n * (n - 1) / 2;
	long long sum = 0;
	
	p[0] = p[1] = 0;
	
	for(i=1;i<=n;i++){
		p[a[i]] = i;
		
		if(a[i] == 0){
			ans -= i - f[i] - 1;
			if(g[p[1]] > i and f[p[1]] < f[i]){
				ans -= min(f[i], p[1]) - max(f[p[1]], f[p[1] + 1]);
			}
		}else{
			ans -= i - f[i] - 1;
			if(g[p[0]] > i and f[p[0]] < f[i]){
				ans -= min(f[i], p[0]) - max(f[p[0]], f[p[0] + 1]);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}