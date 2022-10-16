#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int t,n,a[105],b[105],f[105][10005];
int dfs(int now,int s1,int s2){
	if (f[now][s1]!=-1)return f[now][s1];
	if (now>n)return 0;
	int ans=(n-1)*a[now]*a[now]+(n-1)*b[now]*b[now]+min(2*a[now]*s1+2*b[now]*s2+dfs(now+1,s1+a[now],s2+b[now]),2*a[now]*s2+2*b[now]*s1+dfs(now+1,s1+b[now],s2+a[now]));
	return f[now][s1]=ans;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n;i++)cin>>b[i];
		memset(f,-1,sizeof(f));
		cout<<dfs(1,0,0)<<endl;
	}
	return 0;
}