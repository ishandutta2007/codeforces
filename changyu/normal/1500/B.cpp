#include<bits/stdc++.h>
#define int long long
const int N=5e5+3,A=1e6+3;
int Gcd(int a,int b){return b?Gcd(b,a%b):a;}
int n,m,lcm,x,k,a[N],b[N],c[N+N],d,p[A];
bool Check(int g){
	int r=g/lcm*d,u=0,v=0,gg=g;
	g%=lcm;
	for(;;){
	  if(std::min(u+n,v+m)<=g)r+=c[u-v+N];
	  else break;
	  if(u+n<=v+m)u+=n;else v+=m;
	  if(u==v)break;
	}
	if(u>v){
	  for(int i=1;i<=n;i++)if(u+i<=g&&i+u-v>=1&&i+u-v<=m&&a[i]==b[i+u-v])++r;
	}
	else{
	  for(int i=1;i<=m;i++)if(v+i<=g&&i+v-u>=1&&i+v-u<=n&&b[i]==a[i+v-u])++r;
	}
	return gg-r>=k;
}
signed main(){
	int l,r,md;
	scanf("%lld%lld%lld",&n,&m,&k),x=std::max(n,m)*2;
	lcm=n*m/Gcd(n,m);
	for(int i=1;i<=n;++i)scanf("%lld",a+i),p[a[i]]=i;
	for(int i=1;i<=m;++i){
	  scanf("%lld",b+i);
	  if(p[b[i]])++c[i-p[b[i]]+N];
	}
	for(int u=0,v=0;;){
	  d+=c[u-v+N];
	  //printf("%lld %lld %lld\n",u,v,c[u-v+N]);
	  if(u+n<=v+m)u+=n;else v+=m;
	  if(u==v)break;
	}
	for(l=1,r=4e18;l<r;)md=l+r>>1,Check(md)?r=md:l=md+1;
	printf("%lld\n",l);
	return 0;
}