#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int a, aa, b, bb;
	scanf("%d %d %d %d", &a, &aa, &b, &bb);
	int c, cc;
	scanf("%d:%d", &c, &cc);
	int cur = c * 60 + cc;
	int mx = 23*60 + 59;
	int ans = 0;
	int start = 5 * 60;
	while (start <= mx){
		if (cur + aa > start && start + bb > cur)	ans++;
		start += b;
	}	
	printf("%d\n", ans);
	return 0;
}