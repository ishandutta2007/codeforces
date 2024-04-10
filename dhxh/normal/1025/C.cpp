#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

char a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int t;
	int ans = 1;
	int l = 1;
	
	scanf("%s", a);
	
	n = strlen(a);
	
	t = 0;
	
	for(i=1;i<2 * n;i++){
		if(i % n == t){
			ans = n;
			break;
		}
		
		if(a[i % n] != a[(i - 1 + n) % n]){
			l += 1;
		}else{
			if(l > ans){
				ans = l;
			}
			l = 1;
			t = i % n;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}