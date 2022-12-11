#include<cstdio>
#include<cstring>
#define R register int
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x; 
}
#define N 131072
#define MOD 777777777
int v[3][3];
inline void rw(int&a,int b){if((a+=b)>=MOD)a-=MOD;}
struct data
{
	int z[3][3];
	data operator+(const data&b)
	{
		data c,d;memset(c.z,0,sizeof(c.z));memset(d.z,0,sizeof(d.z));
		for(R i=0;i<3;++i)for(R j=0;j<3;++j)
			for(R k=0;k<3;++k)if(v[j][k])rw(c.z[i][k],z[i][j]);
		for(R i=0;i<3;++i)for(R j=0;j<3;++j)
			for(R k=0;k<3;++k)d.z[i][j]=(d.z[i][j]+1LL*c.z[i][k]*b.z[k][j])%MOD;
		return d;
	}
}f[4],t[N*2+5];
void change(int k,int x){for(t[k+=N]=f[x];k>>=1;)t[k]=t[k<<1]+t[k<<1|1];}
data query(int l,int r)
{
	data lr,rr;int pl=0,pr=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)lr=pl?lr+t[l+1]:(pl=1,t[l+1]);
		if( r&1)rr=pr?t[r-1]+rr:(pr=1,t[r-1]);
	}
	return pl&&pr?lr+rr:pl?lr:rr;
} 
int main()
{
	int n,m,i,j,x;data z;
	n=read();m=read();
	for(i=0;i<3;++i)for(j=0;j<3;++j)v[i][j]=read();
	f[0].z[0][0]=f[0].z[1][1]=f[0].z[2][2]=
	f[1].z[0][0]=f[2].z[1][1]=f[3].z[2][2]=1;
	for(i=1;i<=n;++i)t[i+N]=f[0];
	for(i=N;--i;)t[i]=t[i<<1]+t[i<<1|1];
	while(m--)
	{
		i=read();change(i,read());z=query(1,n);
		for(x=i=0;i<3;++i)for(j=0;j<3;++j)x=(x+z.z[i][j])%MOD;
		printf("%d\n",x);
	}
}