#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 5;

int n, m, t;
int len;
bool flag = false;

int f[maxn][205];
int g[maxn][205];
bool v[maxn][205];
bool vis[maxn];
int p = 0;

char a[maxn];

int ha[205];
int hb[205];
bool vh[205];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	
	a[0] = 1;
	
	scanf("%s", &a[1]);
	len = strlen(a) - 1;
	
	n = read();
	m = read();
	
	if(m <= 100){
		flag = true;
	}
	
	for(i=1;i<=len;i++){
		if(a[i] == '('){
			p++;
			vis[p] = false;
			for(j=0;j<=100;j++){
				v[p][j] = false;
			}
		}else if(a[i] == ')'){
			if(!vis[p - 1]){
				vis[p - 1] = true;
				for(j=0;j<=100;j++){
					f[p - 1][j] = f[p][j];
					g[p - 1][j] = g[p][j];
					v[p - 1][j] = v[p][j];
				}
			}else{
				memset(ha, 0, sizeof(ha));
				memset(hb, 0, sizeof(hb));
				memset(vh, 0, sizeof(vh));
				for(j=0;j<=100;j++){
					for(k=0;k<=100;k++){
						if(v[p - 1][j] and v[p][k]){
							if(!vh[j + k + !flag]){
								ha[j + k + !flag] = f[p - 1][j] + f[p][k];
								hb[j + k + !flag] = g[p - 1][j] + g[p][k];
								vh[j + k + !flag] = true;
							}else{
								ha[j + k + !flag] = max(ha[j + k + !flag], f[p - 1][j] + f[p][k]);
								hb[j + k + !flag] = min(hb[j + k + !flag], g[p - 1][j] + g[p][k]);
							}
							
							if(!vh[j + k + flag]){
								ha[j + k + flag] = f[p - 1][j] - g[p][k];
								hb[j + k + flag] = g[p - 1][j] - f[p][k];
								vh[j + k + flag] = true;
							}else{
								ha[j + k + flag] = max(ha[j + k + flag], f[p - 1][j] - g[p][k]);
								hb[j + k + flag] = min(hb[j + k + flag], g[p - 1][j] - f[p][k]);
							}
						}
					}
				}
				for(j=0;j<=100;j++){
					f[p - 1][j] = ha[j];
					g[p - 1][j] = hb[j];
					v[p - 1][j] = vh[j];
				}
			}
			p--;
		}else if(a[i] == '?'){
			continue;
		}else{
			if(!vis[p]){
				vis[p] = true;
				f[p][0] = a[i] - '0';
				g[p][0] = a[i] - '0';
				v[p][0] = true;
			}else{
				memset(ha, 0, sizeof(ha));
				memset(hb, 0, sizeof(hb));
				memset(vh, 0, sizeof(vh));
				for(j=0;j<=100;j++){
					if(v[p][j]){
						if(!vh[j + !flag]){
							ha[j + !flag] = f[p][j] + a[i] - '0';
							hb[j + !flag] = g[p][j] + a[i] - '0';
							vh[j + !flag] = true;
						}else{
							ha[j + !flag] = max(ha[j + !flag], f[p][j] + a[i] - '0');
							hb[j + !flag] = min(hb[j + !flag], g[p][j] + a[i] - '0');
						}
						
						if(!vh[j + flag]){
							ha[j + flag] = f[p][j] - (a[i] - '0');
							hb[j + flag] = g[p][j] - (a[i] - '0');
							vh[j + flag] = true;
						}else{
							ha[j + flag] = max(ha[j + flag], f[p][j] - (a[i] - '0'));
							hb[j + flag] = min(hb[j + flag], g[p][j] - (a[i] - '0'));
						}
					}
				}
				
				for(j=0;j<=100;j++){
					f[p][j] = ha[j];
					g[p][j] = hb[j];
					v[p][j] = vh[j];
				}
			}
		}
	}
	
	printf("%d\n", f[0][flag ? m : n]);
	
	return 0;
}