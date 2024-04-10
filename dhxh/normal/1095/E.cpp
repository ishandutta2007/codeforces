#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t, k;

char a[maxn];

int f[maxn];
int minx[maxn];
int maxx[maxn];

int main(){
	int i, j;
	int ans = 0;
	int x, y;
	
	scanf("%d", &n);
	scanf("%s", &a[1]);
	
	for(i=1;i<=n;i++){
		if(a[i] == '('){
			f[i] = f[i - 1] + 1;
		}else{
			f[i] = f[i - 1] - 1;
		}
	}
	
	minx[1] = f[1];
	
	for(i=2;i<=n;i++){
		minx[i] = min(minx[i - 1], f[i]);
	}
	
	maxx[n] = f[n];
	
	for(i=n-1;i>0;i--){
		maxx[i] = min(maxx[i + 1], f[i]);
	}
	
	
	if(f[n] == 2 and f[1] > 0){
		for(i=2;i<=n;i++){
			if(maxx[i] >= 2 and a[i] == '('){
				ans++;
			}
			if(f[i] < 0){
				break;
			}
		}
	}else if(f[n] == -2){
		for(i=1;i<n;i++){
			if(maxx[i] >= -2 and a[i] == ')'){
				ans++;
			}
			if(f[i] < 0){
				break;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}