#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;
const ll MOD=998244353;
 
ll m,a[N],n,b[N],mi[N],ans=1;
 
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=1;j<=m;j++) scanf("%d",&b[j]);
	mi[n]=a[n];
	for(int i=n-1;i>=1;i--) mi[i]=min(a[i],mi[i+1]);
	if(mi[1]<b[1])
	{
		puts("0");
		return 0;
	}
	int j=1; ll l=-1,r;
	for(int i=1;i<=n;i++)
	{
		if(mi[i]==b[j]) j++;
	}
	if(j<=m)
	{
		puts("0");
		return 0;
	} 
	j=2;
	mi[n+1]=INF;
	//for(int i=1;i<=n;i++) cout<<mi[i]<<endl;
	for(int i=1;i<=n+1;i++)
	{
		if(mi[i]!=b[j]&&l!=-1)
		{
			//cout<<j<<" "<<l<<" "<<i<<endl;
			j++; r=i;
			ans=ans*(r-l)%MOD;
			l=-1;
		}
		if(mi[i]==b[j]&&l==-1) l=i;
	}
	printf("%lld\n",ans);
	return 0;
}//