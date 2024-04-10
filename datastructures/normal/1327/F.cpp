#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
using namespace std;
int n,k,m,l[500005],r[500005],x[500005],ans=1;
int last[500005],ch[500005],f[500005],sum[500005];
int main(){
	cin>>n>>k>>m;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&l[i],&r[i],&x[i]);
	for (int i=0;i<k;i++){
		memset(last,0,sizeof(last));
		memset(ch,0,sizeof(ch));
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		for (int j=1;j<=m;j++)
			if (x[j]&(1<<i))ch[l[j]]++,ch[r[j]+1]--;
			else last[r[j]]=max(last[r[j]],l[j]);
		for (int j=1;j<=n+1;j++){
			ch[j]+=ch[j-1];
			last[j]=max(last[j],last[j-1]);
		}
		sum[0]=1;
		for (int j=1;j<=n+1;j++){
			if (ch[j]!=0)f[j]=0;
			else if (last[j-1]==0)f[j]=sum[j-1];
			else f[j]=(sum[j-1]-sum[last[j-1]-1]+mod)%mod;
			sum[j]=(sum[j-1]+f[j])%mod;
		}
		ans=1ll*ans*f[n+1]%mod;
	}
	cout<<ans<<endl;
	return 0;
}