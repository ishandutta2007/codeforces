#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char str[105];
int check(int i, int k){
	int j = i, d = k - i, cnt = 0;
	while(j <= n){
		if(str[j] == '.') return cnt;
		cnt ++;
		j += d;
	}
	return cnt;
}
	
int main(){
	scanf("%d", &n);
	scanf("%s", str + 1);
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			if(check(i, j) >= 5){
				printf("yes\n");
				return 0;
			}
		}
	}
	printf("no\n");
	return 0;
}