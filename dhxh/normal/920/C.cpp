#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int l = 0, r = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<n;i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == '1'){
			if(l == 0){
				l = i;
				r = i;
			}else{
				r = i;
			}
		}else{
			if(l != 0){
				sort(a + l, a + r + 2);
			}
			l = r = 0;
		}
	}
	
	if(l != 0){
		sort(a + l, a + r + 2);
	}
	
	for(i=1;i<=n;i++){
		if(a[i] != i){
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	
	return 0;
}