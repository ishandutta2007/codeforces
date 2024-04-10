#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

char a[maxn], b[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		
		for(i=1;i<=n;i++){
			scanf(" %c", &a[i]);
		}
		
		for(i=1;i<=n;i++){
			scanf(" %c", &b[i]);
		}
		
		bool flag = false;
		for(i=1;i<=n;i++){
			if(a[i] > b[i]){
				flag = true;
			}
		}
		
		if(flag){
			printf("-1\n");
			continue;
		}
		
		int ans = 0;
		
		for(i='a';i<'a'+20;i++){
			char mn = 'a' + 30;
			for(j=1;j<=n;j++){
				if(a[j] == i){
					if(a[j] != b[j]){
						mn = min(mn, b[j]);
					}
				}
			}
			
			if(mn != 'a' + 30){
				ans++;
				for(j=1;j<=n;j++){
					if(a[j] == i){
						if(a[j] != b[j]){
							a[j] = mn;
						}
					}
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}