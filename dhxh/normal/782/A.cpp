#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool s[100005] = {0};

int ans = 0;
int c = 0;
int n;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x;
	
	n = read();
	
	for(i=1;i<=2*n;i++){
		x = read();
		if(s[x]){
			c--;
			s[x] = false;
		}else{
			c++;
			s[x] = true;
			ans = max(ans, c);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}