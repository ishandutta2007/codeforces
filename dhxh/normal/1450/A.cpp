#include <bits/stdc++.h>

using namespace std;

int n, m, t;

char str[1005];

int a[1005];

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	a['t'] = 6;
	a['r'] = 5;
	a['y'] = 4;
	a['g'] = 3;
	a['u'] = 2;
	a['b'] = 1;
	
	while(t--){
		scanf("%d", &n);
		scanf("%s", str);
		
		sort(str, str + n, cmp);
		
		printf("%s\n", str);
	}
	
	return 0;
}