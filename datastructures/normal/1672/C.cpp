#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000
using namespace std;
int t,n,a[200005],f[200005][2][2][3];
int dfs(int now,int fg1,int fg2,int cnt){
	if (cnt>2)return inf;
	if (f[now][fg1][fg2][cnt]!=-1)return f[now][fg1][fg2][cnt];
	if (now==1)return dfs(now+1,fg1,fg2,cnt);
	if (now>n){
		if (cnt<=1)return 0;
		return inf;
	}
	int qwq=0;
	if (now>1&&a[now]==a[now-1]&&fg2==0)qwq=1;
	return f[now][fg1][fg2][cnt]=min(dfs(now+1,qwq,0,cnt+qwq),1+dfs(now+1,1,1,cnt+1-fg1));
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=0;i<=n+1;i++)
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					for (int l=0;l<3;l++)
						f[i][j][k][l]=-1;
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
}