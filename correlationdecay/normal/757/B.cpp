#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#define maxn 100009
using namespace std;
int n, cnt[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n;i++){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int ans = 1;
	for(int i= 2; i<maxn;i++){
		int cur = 0;
		for(int j=i;j<maxn;j+=i)
			cur += cnt[j];
		ans=max(ans,cur);
	}
	printf("%d\n", ans);
	return 0;
}