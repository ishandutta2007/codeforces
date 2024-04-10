#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int mod=1e9+6,mod1=1e9+7;
int f1,f2,f3,c,ans,mi;LL n;
struct node{
	int f[6][6],n;
	void clear(){memset(f,0,sizeof(f));}
	void init(){
		for(int i=1;i<=n;i++)f[i][i]=1;
	}
	void print(){cout<<n<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("%d ",f[i][j]);
			puts("");
		}
	}
	node operator *(node b){
		node ret;ret.n=n;
		ret.clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					(ret.f[i][j]+=1ll*f[i][k]*b.f[k][j]%mod)%=mod;
		return ret;
	}
}a,b;
node ksm(node x,LL y){
	node ret;ret.n=x.n;
	ret.clear();ret.init();
	while(y){//ret.print();
		if(y&1)ret=ret*x;
		x=x*x;y>>=1;
	}
	return ret;
}
int power(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod1;
		x=1ll*x*x%mod1;y>>=1;
	}
	return ret;
}
int main(){
	scanf("%lld%d%d%d%d",&n,&f1,&f2,&f3,&c);
	a.clear();
	for(int i=1;i<=3;i++)a.f[1][i]=1;
	a.f[2][1]=1;a.f[3][2]=1;
	a.n=3;
	b=ksm(a,n-3);
	ans=power(f1,b.f[1][3]);
	ans=1ll*ans*power(f2,b.f[1][2])%mod1;
	ans=1ll*ans*power(f3,b.f[1][1])%mod1;
	a.clear();
	for(int i=1;i<=3;i++)a.f[1][i]=1;
	a.f[1][4]=2;a.f[1][5]=-4;
	a.f[2][1]=1;a.f[3][2]=1;
	a.f[4][4]=1;a.f[4][5]=1;a.f[5][5]=1;
	a.n=5;
	b=ksm(a,n-3);
	ans=1ll*ans*power(c,1ll*b.f[1][4]*3%mod+b.f[1][5])%mod1;
	printf("%d\n",ans);
	return 0;
}
//16 97 41 37 11