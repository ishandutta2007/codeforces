#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m;

int a[maxn];

int f[maxn][21];

int last[21];

int main(){
	int i, j, k;
	int x, y;
	memset(f, 0x3f, sizeof(f));
	memset(last, 0x3f, sizeof(last));
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=n;i>0;i--){
		for(j=0;j<=20;j++){
			if((a[i] >> j) & 1){
				f[i][j] = i;
				if(last[j] != inf){
					for(k=0;k<=20;k++){
						f[i][k] = min(f[i][k], f[last[j]][k]);
					}
				}
				last[j] = i;
			}
		}
	}
	
	while(m--){
		scanf("%d%d", &x, &y);
		bool flag = false;
		for(j=0;j<=20;j++){
			if((a[y] >> j) & 1){
				if(y >= f[x][j]){
					flag = true;
					break;
				}
			}
		}
		if(flag){
			printf("Shi\n");
		}else{
			printf("Fou\n");
		}
	}
	
	return 0;
}