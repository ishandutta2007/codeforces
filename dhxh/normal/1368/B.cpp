#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

char ch[20] = "codeforces";

long long cnt[20];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	scanf("%lld", &n);
	long long m = 1;
	
	for(i=0;i<10;i++) cnt[i] = 1;
	
	while(m < n){
		for(i=0;i<10;i++){
			m /= cnt[i];
			cnt[i]++;
			m *= cnt[i];
			if(m >= n) break;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=1;j<=cnt[i];j++){
			printf("%c", ch[i]);
		}
	}
	printf("\n");
	
	return 0;
}