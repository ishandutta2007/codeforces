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

char a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			scanf(" %c", &a[i]);
		}
		
		string ans;
		int x = 0, y = 0;
		while(x < n and a[x + 1] == '0') x++;
		while(n - y > 0 and a[n - y] == '1') y++;
		
		for(i=1;i<=x;i++) ans.push_back('0');
		if(x + y != n){
			ans.push_back('0');
		}
		for(i=1;i<=y;i++) ans.push_back('1');
		
		printf("%s\n", ans.c_str());
	}
	
	return 0;
}