#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,book[5000005],f[5000005],cnt[5000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ans=m,val=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (book[x]==0){
				book[x]=1;
				cnt[f[x]]++;
			}
		}	
		for (int i=1;i<=m;i++){
			if (book[i]==1)cnt[f[i]]--;
			f[i]=i;
			if (book[i]==1)cnt[f[i]]++;
			for (int j=1;j<=m/i;j++){
				if (book[j*i]==1)cnt[f[j*i]]--;
				f[j*i]=max(f[j*i],min(f[j],i));
				if (book[j*i]==1)cnt[f[j*i]]++;
			}
			while(cnt[val]==0)val++;
			if (val>0)ans=min(ans,i-val);
		}
		for (int i=0;i<=m+1;i++)f[i]=book[i]=cnt[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}