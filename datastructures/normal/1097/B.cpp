#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[105],fg;
void dfs(int now,int s){
	if (now>n){
		s%=360;
		if (s==0)fg=1;
		return;
	}
	dfs(now+1,s+a[now]);
	dfs(now+1,s-a[now]);
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	if (fg==1)puts("YES");
	else puts("NO");
	return 0;
}