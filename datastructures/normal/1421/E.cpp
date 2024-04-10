#include <iostream>
#include <cstdio>
#include <cstring> 
#define int long long
#define inf 1000000000000000
using namespace std;
int n,a[200005],f[200005][3][2][2];
inline int dfs(int now,int nowm,int fg,int last){
	if (f[now][nowm][fg][last]!=-1)return f[now][nowm][fg][last];
	if (now>n){
		if (nowm==1&&fg==1)return 0;
		else return -inf;
	}
	return f[now][nowm][fg][last]=max(a[now]+dfs(now+1,(nowm+1)%3,fg|(last==1),1),-a[now]+dfs(now+1,(nowm+2)%3,fg|(last==0),0));
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if (n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	memset(f,-1,sizeof(f));
	int ans=max(a[1]+dfs(2,1,0,1),-a[1]+dfs(2,2,0,0));
	cout<<ans<<endl;
	return 0;
}