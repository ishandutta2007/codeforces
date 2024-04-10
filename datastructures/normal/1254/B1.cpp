#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define inf 1000000000000000
using namespace std;
int n,a[1000005],b[1000005],val[1000005],sum,ans=inf;
int c[1000005],tot;
int awa(int x){
	int s=0;
	int p=1,qwq=val[1];
	while(qwq*2<=x)p++,qwq+=val[p];
	for (int i=1;i<p;i++)s+=(c[p]-c[i])*val[i];
	for (int i=p+1;i<=tot;i++)s+=(c[i]-c[p])*val[i];
	return s;
}
int calc(int x){
	int s=0;
	for (int i=1;i<=n;i++)b[i]=a[i]%x;
	for (int i=1;i<=n;){
		if (b[i]==0){
			i++;
			continue;
		}
		int j=i,qwq=x;
		tot=0;
		while(qwq>b[j]){
			++tot; 
			c[tot]=j;
			val[tot]=b[j];
			qwq-=b[j];
			b[j]=0;
			j++;
		}
		++tot;
		c[tot]=j;
		val[tot]=qwq;
		b[j]-=qwq;
		qwq=0;
		s+=awa(x);
		i=j;
	}
	return s;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
	for (int i=2;i*i<=sum;i++){
		if (sum%i!=0)continue;
		ans=min(ans,calc(i));
		while(sum%i==0)sum/=i;
	}
	if (sum>1)ans=min(ans,calc(sum));
	if (ans<inf)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}