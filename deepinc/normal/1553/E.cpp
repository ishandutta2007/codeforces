#include<bits/stdc++.h>
using namespace std;
int n,m,a[333333],cnt[333333],ans,b[333333],al[333333];
bool chk(int p){
	for(int i=1;i<=n;++i)b[i]=a[i+p>n?i+p-n:i+p],al[i]=0;
	int t=0,M=m;
	for(int i=1;i<=n;++i)if(!al[i]){
		int p=i,c=0;
		while(!al[p])al[p]=1,c++,p=b[p];
		M-=c-1;
	}return M>=0;
}
int main(){
	int T;cin>>T;while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),cnt[i>=a[i]?i-a[i]:i-a[i]+n]++;
		for(int i=0;i<n;++i)if(cnt[i]>=n/3&&chk(i))ans++;else cnt[i]=0;
		printf("%d ",ans);
		for(int i=0;i<n;++i)if(cnt[i])printf("%d ",i),cnt[i]=0;
		ans=0; puts("");
	}
}