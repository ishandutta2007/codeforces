#include <iostream>
#include <cstdio>
#define ll long long
#define maxv 20000000
using namespace std;
int p[2000005],tot;
bool isp[20000005];
int n,a[100005];
int cnt[20000005];
ll f[20000005],ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	isp[0]=isp[1]=1;
	for (int i=2;i<=maxv;i++){
		if (isp[i]==0)p[++tot]=i;
		for (int j=1;j<=tot&&p[j]<=maxv/i;j++){
			isp[p[j]*i]=1;
			if (i%p[j]==0)break;
		}
	}
	for (int i=1;i<=tot;i++)
		for (int j=maxv/p[i];j>0;j--)
			cnt[j]+=cnt[j*p[i]];
	for (int i=maxv;i>=1;i--){
		if (cnt[i]==0)continue;
		f[i]=1ll*cnt[i]*i;
		for (int j=i*2;j<=maxv;j+=i)
			if (cnt[j]>0)f[i]=max(f[i],1ll*i*(cnt[i]-cnt[j])+f[j]);
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}