#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

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
		int a, b;
		a = read();
		b = read();
		
		int x, y;
		int ma = 0, mb = 0;
		
		for(i=1;i<=a;i++){
			x = read();
			ma = max(ma, x);
		}
		
		for(i=1;i<=b;i++){
			x = read();
			mb = max(mb, x);
		}
		
		if(ma > mb){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}