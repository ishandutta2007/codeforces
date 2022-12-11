#include<bits/stdc++.h>
using namespace std;
int n,k,z[222],a[111],b[111],r[222];
int main(){
	int t;scanf("%d",&t);while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;++i){
			scanf("%d%d",&a[i],&b[i]),z[a[i]]=z[b[i]]=1;
			if(a[i]>b[i])swap(a[i],b[i]);
		}
		for(int c=0,i=1;i<=n+n;++i)if(!z[i])r[++c]=i;
		sort(r+1,r+1+n-k+n-k);
		int m=n-k;
		for(int i=1;i<=m;++i)a[++k]=r[i],b[k]=r[i+m];
		for(int i=1;i<=n;++i)cerr<<a[i]<<' '<<b[i]<<endl;
		int ans=0;
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if((a[i]-a[j])*(b[i]-b[j])>0&&max(a[i],a[j])<min(b[i],b[j]))ans++;
		for(int i=1;i<=n+n;++i)z[i]=0;
		printf("%d\n",ans);
	}
}