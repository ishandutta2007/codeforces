#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int t,n,a[105],fg;
map<int,int> c;
void dfs(int now,int sum){
	if (now>n){
		if (c[sum])fg=1;
		return;
	}
	c[a[now]]++;
	dfs(now+1,sum);
	c[a[now]]--;
	dfs(now+1,sum+a[now]);
	dfs(now+1,sum-a[now]);
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		fg=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<i;j++)
				if (a[i]==a[j])fg=1;
		dfs(1,0);
		if (fg==1)puts("YEs");
		else puts("NO");
		c.clear();
	}
	return 0;
}