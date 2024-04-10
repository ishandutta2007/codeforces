#include<bits/stdc++.h>
#define int long long
const int N=2000005,mod=998244353;
using namespace std;

int p[N],v[N],c;
int jc[N],ij[N],iv[N],sm[N];
int n,k;
int g[N],s[N];

int gsc(int a,int b){
	int ans=1;
	for(int i=1;i<=b;i<<=1,a=a*a%mod)
		if(b&i)ans=ans*a%mod;
	return ans;
}int inv(int k){return gsc(k,mod-2);}

void init(){
	for(int i=2;i<N;i++){
		if(!v[i])p[++c]=i;
		for(int j=1;i*p[j]<N;j++){
			v[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	jc[0]=ij[0]=iv[0]=1;
	for(int i=1;i<N;i++)jc[i]=jc[i-1]*i%mod;
	ij[N-1]=inv(jc[N-1]);
	for(int i=N-2;i>=0;i--)ij[i]=ij[i+1]*(i+1)%mod;
	for(int i=1;i<N;i++)iv[i]=ij[i]*jc[i-1]%mod;
	sm[0]=1;
	for(int i=1;i<N;i++)sm[i]=(sm[i-1]+((i&1)?-1:1)*ij[i])%mod;
}

int pw[N];
int S(int x,int y){
	y=min(x,y);
	int res=0;
	for(int i=1;i<=y;i++){
		if(!v[i])pw[i]=gsc(i,x);
		res+=pw[i]*ij[i]%mod*sm[y-i]%mod;
		for(int j=1;i*p[j]<=y;j++){
			pw[i*p[j]]=pw[i]*pw[p[j]]%mod;
			if(i%p[j]==0)break;
		}
	}
	return (res%mod+mod)%mod;
}

int calc(int i){
	if(g[i])return g[i];
	g[i]=S(i,k);
	for(int j=2;j<=i;j++)
		g[i]-=calc((i+j-1)/j);
	g[i]=(g[i]%mod+mod)%mod;
	return g[i];
}

void solve(){
	cin>>n>>k;
	if(n==1||k==1){
		cout<<1<<endl;
		exit(0);
	}
	init();
//cout<<S(n,k)<<endl;
	cout<<calc(n)<<endl;
}

main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	solve();
}