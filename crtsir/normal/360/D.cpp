#include<bits/stdc++.h>
using namespace std;
int B=1000000;
vector<int>pri;
int n,m,p,rt,invrt;
void divide(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0){
			while(x%i==0)
				x/=i;
			pri.push_back(i);
		}
	if(x^1)pri.push_back(x);
}
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)
			ret=1ll*ret*x%p;
		x=1ll*x*x%p;
		times>>=1;
	}return ret;
}
int qaq=8388607,N=8388608,T=1003;
int tot,hd[8388608],nxt[8200001],ky[8200001],vl[8200001];
void ins(int x,int v){
	int fg=(x&qaq);
	++tot;
	ky[tot]=x;vl[tot]=v;
	nxt[tot]=hd[fg];hd[fg]=tot;
}
int fnd(int x){
	int fg=(x&qaq);
	for(int i=hd[fg];i;i=nxt[i])
		if(ky[i]==x)return vl[i];
	return -1;
}
int tmp;
long long inv[1003];
int findpw(int x){
	for(int i=0;i<T;i++){
		tmp=fnd(x*inv[i]%p);
		if(tmp!=-1)return i*B+tmp;
	}
}
int a[10003],dp[3003];
int main(){
	cin>>n>>m>>p;
	if(p==2){cout<<1;return 0;}
	divide(p-1);
	B=min(B,p-1);
	int nwtmp=2;
	while(!rt){
		rt=nwtmp;
		for(int i=0;i<pri.size();i++)
			if(mypow(nwtmp,(p-1)/pri[i])==1)
				rt=0;
		nwtmp++;
	}invrt=mypow(rt,p-2);
	int pwrt=mypow(invrt,B),nw=1;
	for(int i=0;i<B;i++){
		ins(nw,i);
		nw=1ll*nw*rt%p;
	}
	inv[0]=1;
	for(int i=1;i<T;i++)
		inv[i]=inv[i-1]*pwrt%p;
	int b=p-1,tmpb;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		a[i]=__gcd(p-1,findpw(a[i]));
	}
	for(int i=0;i<m;i++){
		scanf("%d",&tmpb);
		tmpb%=(p-1);
		b=__gcd(b,tmpb);
	}
	for(int i=0;i<n;i++)
		a[i]=__gcd(p-1ll,1ll*a[i]*b%(p-1));
	pri.clear();
	for(int i=1;i<=sqrt(p-1);i++)
		if((p-1)%i==0)
			pri.push_back(i),
			pri.push_back((p-1)/i);
	sort(pri.begin(),pri.end());
	pri.erase(unique(pri.begin(),pri.end()),pri.end()); 
	for(int i=0;i<pri.size();i++)
		dp[i]=(p-1)/pri[i];
	for(int i=pri.size()-1;i>=0;i--)
		for(int j=i+1;j<pri.size();j++)
			if(pri[j]%pri[i]==0)
				dp[i]-=dp[j];int ans=0;
	for(int i=0;i<pri.size();i++){
		bool ok=0;
		for(int j=0;j<n;j++)
			if(a[j]&&pri[i]%a[j]==0)
				ok=1;
		if(ok)ans+=dp[i];
	}cout<<ans;
}