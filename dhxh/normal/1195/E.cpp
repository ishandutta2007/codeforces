#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 3000 + 5;

long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m, t;
int a, b;

long long s[maxn][maxn];
long long f[maxn][maxn];
long long h[maxn][maxn];

long long minx[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	long long g, x, y, z;
	long long ans = 0;
	
	cin >> n >> m >> a >> b;
	cin >> g >> x >> y >> z;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			s[i][j] = g;
			g = (g * x + y) % z;
		}
	}
	
	for(j=1;j<=m;j++){
		for(i=0;i+a<=n;i+=a){
			minx[i + a] = s[i + a][j];
			for(k=i+a-1;k>i;k--){
				minx[k] = min(s[k][j], minx[k + 1]);
			}
		}
		
		for(i=a;i<=n;i++){
			if(i % a == 0){
				f[i][j] = minx[i - a + 1];
				g = inf;
			}else{
				g = min(g, s[i][j]);
				f[i][j] = min(minx[i - a + 1], g);
			}
		}
	}
	
	for(i=a;i<=n;i++){
		for(j=0;j+b<=m;j+=b){
			minx[j + b] = f[i][j + b];
			for(k=j+b-1;k>j;k--){
				minx[k] = min(f[i][k], minx[k + 1]);
			}
		}
		
		for(j=b;j<=m;j++){
			if(j % b == 0){
				h[i][j] = minx[j - b + 1];
				g = inf;
			}else{
				g = min(g, f[i][j]);
				h[i][j] = min(minx[j - b + 1], g);
			}
			ans += h[i][j];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}