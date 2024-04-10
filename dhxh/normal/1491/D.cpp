#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		if(n > m){
			printf("NO\n");
			continue;
		}
		
		bool flag = true;
		
		int a = 0, b = 0;
		
		for(i=0;i<=30;i++){
			a += ((n >> i) & 1);
			b += ((m >> i) & 1);
			if(b > a){
				flag = false;
				break;
			}
		}
		
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}