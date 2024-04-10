#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t, q;

int a[maxn];

int c[10];

int main(){
	int i, j;
	
	
	scanf("%d%d", &n, &q);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	
	while(q--){
		int p, x;
		scanf("%d%d", &p, &x);
		
		if(p == 1){
			c[a[x]]--;
			a[x] = !a[x];
			c[a[x]]++;
		}else{
			if(x <= c[1]){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}
	}
	
	return 0;
}