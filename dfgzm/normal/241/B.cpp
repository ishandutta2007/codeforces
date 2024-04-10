#include<bits/stdc++.h>
#define Mid (L+R>>1)
#define ll long long
#define int long long
using namespace std;
const int maxn=50010,mod=1e9+7;
int i,j,n,m,a[maxn];ll k;
int check(int L1,int R1,int L2,int R2,int b,int w,int last1,int last2){
	if(R1<L1 || R2<L2 || b<0)return 0;
	int d1=lower_bound(a+L1,a+R1+1,(1<<b)+last1)-a-1;
	int d2=lower_bound(a+L2,a+R2+1,(1<<b)+last2)-a-1;
	ll ans=0;
	if((1<<b)>=w){
		ans+=(d1-L1+1)*(R2-d2);
		if(L1!=L2)ans+=(d2-L2+1)*(R1-d1);
		ans+=check(L1,d1,L2,d2,b-1,w,last1,last2);
		ans+=check(d1+1,R1,d2+1,R2,b-1,w,last1+(1<<b),last2+(1<<b));
	}else{
		ans+=check(L1,d1,d2+1,R2,b-1,w-(1<<b),last1,last2+(1<<b));
		if(L1!=L2)ans+=check(d1+1,R1,L2,d2,b-1,w-(1<<b),last1+(1<<b),last2);
	}
//	cout<<"check "<<L1<<' '<<d1<<' '<<R1<<' '<<L2<<' '<<d2<<' '<<R2<<' '<<b<<' '<<w<<' '<<ans<<' '<<last1<<' '<<last2<<endl;
	return ans;
}
int Bit[maxn][35],bit[35][2];
ll sum(int L1,int R1,int L2,int R2){
	for(int i=0;i<=30;i++)bit[i][0]=Bit[R1][i]-Bit[L1-1][i];
	for(int i=0;i<=30;i++)bit[i][1]=Bit[R2][i]-Bit[L2-1][i];
	ll ans=0;
	for(int i=0;i<=30;i++)ans+=1ll*bit[i][0]*(R2-L2+1-bit[i][1])*(1<<i)%mod;
	for(int i=0;i<=30;i++)ans+=1ll*bit[i][1]*(R1-L1+1-bit[i][0])*(1<<i)%mod;
//	cout<<"sum "<<L1<<' '<<R1<<' '<<L2<<' '<<R2<<' '<<ans<<endl;
	return ans%mod;
}
ll getans(int L1,int R1,int L2,int R2,int b,int w,int last1,int last2){
	if(R1<L1 || R2<L2 || b<0)return 0;
	int d1=lower_bound(a+L1,a+R1+1,(1<<b)+last1)-a-1;
	int d2=lower_bound(a+L2,a+R2+1,(1<<b)+last2)-a-1;
	ll ans=0;
	if((1<<b)>=w){
		ans+=sum(L1,d1,d2+1,R2);
		if(L1!=L2)ans+=sum(d1+1,R1,L2,d2);
		ans+=getans(L1,d1,L2,d2,b-1,w,last1,last2);
		ans+=getans(d1+1,R1,d2+1,R2,b-1,w,last1+(1<<b),last2+(1<<b));
	}else{
		ans+=getans(L1,d1,d2+1,R2,b-1,w-(1<<b),last1,last2+(1<<b));
		if(L1!=L2)ans+=getans(d1+1,R1,L2,d2,b-1,w-(1<<b),last1+(1<<b),last2);
	}
//	cout<<"check "<<L1<<' '<<d1<<' '<<R1<<' '<<L2<<' '<<d2<<' '<<R2<<' '<<b<<' '<<w<<' '<<ans<<endl;
	return ans%mod;
}
signed main(){
	cin>>n>>k;
	if(!k)puts("0"),exit(0);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		for(j=0;j<=30;j++)
			Bit[i][j]=Bit[i-1][j]+((a[i]&(1<<j))?1:0);
	ll L=0,R=2147483647;
	while(L<=R){
//		cout<<"try "<<Mid<<endl;
		if(check(1,n,1,n,30,Mid,0,0)>=k)L=Mid+1;
		else R=Mid-1;
	}
//	cout<<"ans="<<L-1<<endl;
//	cout<<getans(1,n,1,n,30,L,0,0)<<endl;
	cout<<(getans(1,n,1,n,30,L,0,0)+(L-1)*(k-check(1,n,1,n,30,L,0,0)))%mod<<endl;
	return 0;
}
/*
4 2
141 146 466 789 
*/