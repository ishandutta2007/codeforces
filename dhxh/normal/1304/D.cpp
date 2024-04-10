#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int t;
int n;

char s[maxn];
int a[maxn];

int main(){
	int i, j, k;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=2;i<=n;i++){
			scanf(" %c", &s[i]);
		}
		
		int c = n + 1;
		for(i=1;i<=n;i+=j){
			if(i == n){
				a[i] = --c;
				break;
			}
			if(s[i + 1] == '>'){
				j = 1;
				a[i] = --c;
			}else{
				for(j=1;i+j<=n;j++){
					if(s[i + j] != '<') break;
				}
				
				for(k=0;k<=j;k++){
					a[i + k] = c - j + k;
				}
				c -= j;
			}
		}
		
		for(i=1;i<=n;i++){
			printf("%d ", a[i]);
		}
		printf("\n");
		
		c = 0;
		
		for(i=1;i<=n;i+=j){
			if(i == n){
				a[i] = ++c;
				break;
			}
			if(s[i + 1] == '<'){
				j = 1;
				a[i] = ++c;
			}else{
				for(j=1;i+j<=n;j++){
					if(s[i + j] != '>') break;
				}
				
				for(k=0;k<=j;k++){
					a[i + k] = c + j - k;
				}
				c += j;
			}
		}
		
		for(i=1;i<=n;i++){
			printf("%d ", a[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}