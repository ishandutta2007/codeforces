#include <bits/stdc++.h>

#define MAXN (5010)

int n;
char str[MAXN];
bool mat[MAXN][MAXN];

int main(){
	scanf("%s", str);
	n = strlen(str);
	
	for(int i = 0; i < n; ++ i){
		int left = 0, right = 0;
		for(int j = i; j < n; ++ j){
			left += str[j] == '(' || str[j] == '?';
			right += str[j] == ')';
			if(left < right) break;
			mat[i][j] = (i + j & 1);
		}
	}
	
	int ans = 0;
	
	for(int i = n - 1; ~i; -- i){
		int left = 0, right = 0;
		for(int j = i; ~j; -- j){
			left += str[j] == '(';
			right += str[j] == ')' || str[j] == '?';
			if(right < left) break;
			if(mat[j][i] && (i + j & 1)){
				++ ans;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}