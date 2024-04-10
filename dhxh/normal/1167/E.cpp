#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

int a[maxn];

int f[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int l, r = 2;
	int minx = 0x3f3f3f3f, maxx = 0;
	long long ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(!f[a[i]][0]){
			f[a[i]][0] = f[a[i]][1] = i;
		}else{
			f[a[i]][1] = i;
		}
	}
	
	for(i=m;i>0;i--){
		if(f[i][0]){
			if(f[i][1] < minx){
				minx = f[i][0];
			}else{
				r = i + 1;
				break;
			}
		}
	}
	ans += m - r + 2;
	l = r;
	
	for(i=1;i<m;i++){
		if(!f[i][0]){
			l = max(l, i + 2);
			ans += m - l + 2;
			continue;
		}
		if(f[i][0] > maxx){
			maxx = f[i][1];
			r = max(r, i + 1);
			while(r <= m){
				if(f[r][0]){
					if(f[r][0] < maxx){
						l = r + 1;
					}else{
						break;
					}
				}
				r++;
			}
			l = max(l, i + 2);
			ans += m - l + 2;
		}else{
			break;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}