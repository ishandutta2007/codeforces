#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e7;
int pri[3000000],tot;
bitset<N+3>flg;
void init(){
	flg[1]=1;
	for(int i=2;i<=N;i++){
		if(!flg[i])pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=N;j++){
			flg[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int a[100004];
ll f[20000005],ans;
int n,dv[20000005];
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f[a[i]]++;
	for(int i=1;i<=N;i++){
		if(i>N/n)for(int j=i;j<=N;j+=i)dv[i]+=f[j];
		else for(int j=1;j<=n;j++)dv[i]+=(a[j]%i==0);
	}
	for(int i=1;i<=N;i++)f[i]=(ll)dv[i]*i;
	for(int i=N;i;i--)if(dv[i]>0){
		for(int j=1,k=i*2;k<=N&&j<=tot;j++,k=i*pri[j])
			f[i]=max(f[i],f[k]+(ll)i*(dv[i]-dv[k]));
		ans=max(ans,f[i]);
	}
	printf("%lld",ans);
}