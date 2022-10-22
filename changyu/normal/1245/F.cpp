#include<cstdio>
const int K=32;
typedef long long ll;
int a[K],k,l,flag,tmp[K];ll f[K][4],g[K][2],h[K][2];
inline ll Calc(int n,int m){
	if(n<0||m<0)return 0;
	if(!n&&!m)return 1;
	if(!n)return m+1;
	if(!m)return n+1;
	ll res=0;
	for(int j=0;j<K;j++)tmp[j]=0;
	for(k=0;n;n>>=1)tmp[++k]=n&1;
	for(int j=k;j;j--)a[j] =tmp[k-j+1]<<1;
	for(int j=0;j<K;j++)tmp[j]=0;
	for(l=0;m;m>>=1)tmp[++l]=m&1;
	for(int j=k;j;j--)a[j]+=tmp[k-j+1];
	for(int j=0;j<K;j++){
	  for(int x=0;x<4;x++)f[j][x]=0;
	  for(int x=0;x<2;x++)g[j][x]=0;
	  for(int x=0;x<2;x++)h[j][x]=0;
	}
	for(int x=0;x<3;x++)
	  if((x&1)<(a[1]&1)&&(x>>1)<(a[1]>>1)){
		f[1][x]=1;
		if(k==1)res++;
	  }
	for(int x=0;x<2;x++)
	  if(!(x&a[1]>>1)&&x<(a[1]&1)){
		g[1][x]=1;
		if(k==1)res++;
	  }
	for(int x=0;x<2;x++)
	  if(!(x&a[1]&1)&&x<(a[1]>>1)){
		h[1][x]=1;
		if(k==1)res++;
	  }
	flag=a[1]<3;
	for(int j=2;j<=k;j++){
	  for(int x=0;x<3;x++){
		f[j][x]=0;
		for(int y=0;y<3;y++)
		  f[j][x]+=f[j-1][y];
		if((x>>1)<(a[j]>>1))
		  f[j][x]+=g[j-1][0]+g[j-1][1];
		if((x&1)<(a[j]&1))
		  f[j][x]+=h[j-1][0]+h[j-1][1];
		if((x&1)<(a[j]&1)&&(x>>1)<(a[j]>>1))
		  f[j][x]+=flag;
		if(j==k)res+=f[k][x];
	  }
	  for(int x=0;x<2;x++)if(!(x&a[j]>>1)){
		g[j][x]=0;
		for(int y=0;y<2;y++)
		  g[j][x]+=g[j-1][y];
		if(x<(a[j]&1))g[j][x]+=flag;
		if(j==k)res+=g[k][x];
	  }
	  for(int x=0;x<2;x++)if(!(x&a[j]&1)){
		h[j][x]=0;
		for(int y=0;y<2;y++)
		  h[j][x]+=h[j-1][y];
		if(x<(a[j]>>1))h[j][x]+=flag;
		if(j==k)res+=h[k][x];
	  }
	  if(a[j]==3)flag=0;
	}
	return res+flag;
}
signed main(){
	int T,l,r;scanf("%d",&T);for(;T--;)scanf("%d%d",&l,&r),printf("%lld\n",Calc(r,r)+Calc(l-1,l-1)-2*Calc(r,l-1));
	return 0;
}