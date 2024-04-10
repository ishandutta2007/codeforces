#include <bits/stdc++.h>

using namespace std;

int n, m;

char str[10];
int a[10];
int pw[10];

bool check(int x){
	if(n > 1 and x / pw[n - 1] % 10 == 0) return false;
	int X = -1;
	for(int i=0;i<n;i++){
		int p = x / pw[i] % 10;
		if(str[i] == 'X'){
			if(X == -1){
				X = p;
			}else{
				if(X != p) return false;
			}
		}else if(str[i] != '_'){
			if(str[i] - '0' != p) return false;
		}
	}

	return true;
}

int main(){
	int i, j;

	pw[0] = 1;
	for(i=1;i<=9;i++) pw[i] = pw[i - 1] * 10;

	scanf("%s", str);

	n = strlen(str);

	reverse(str, str + n);

	int ans = 0;
	for(i=0;i<pw[n];i+=25){
		ans += check(i);
	}
	printf("%d\n", ans);

	return 0;
}