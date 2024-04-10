#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=X*10+C-'0';
	return X;
}
#define MN 1000000
#define MOD 1000000007
int a[MN+5],p2[MN+5],r2[MN+5],pw[7];
struct data
{
	int s1,s2,sz;
	data(int s1=0,int s2=0,int sz=0):s1(s1),s2(s2),sz(sz){}
	void operator+=(const data&b)
	{
		s2=(1LL*s2*p2[b.sz]+1LL*b.s2*p2[sz]+2LL*s1*b.s1)%MOD;
		s1=(1LL*s1*p2[b.sz]+1LL*b.s1*p2[sz])%MOD;
		sz+=b.sz;
	}
	void operator-=(const data&b)
	{
		sz-=b.sz;
		s1=((s1-1LL*b.s1*p2[sz])%MOD+MOD)*r2[b.sz]%MOD;
		s2=((s2-2LL*s1*b.s1-1LL*b.s2*p2[sz])%MOD+MOD)*r2[b.sz]%MOD;
	}
}s[MN+5];
void solve1(int x,int k,int d,int p)
{
	if(d>5){if(x!=k)if(p>0)s[x]+=s[k];else s[x]-=s[k];return;}
	solve1(x,k,d+1,p);
	if(k%pw[d+1]/pw[d]<9)solve1(x,k+pw[d],d+1,-p);
}
inline int mod(int x){if(x>=MOD)x-=MOD;if(x<0)x+=MOD;return x;}
void solve2(int x,int k,int d,int p)
{
	if(d>5){if(x!=k)s[x].s2=mod(s[x].s2+p*s[k].s2);return;}
	solve2(x,k,d+1,p);
	if(k%pw[d+1]/pw[d]<9)solve2(x,k+pw[d],d+1,-p);
}
int main()
{
	B[fread(B,1,1<<26,stdin)]=0;
	int n=read(),i;long long ans=0;
	while(n--)++a[read()];
	for(p2[0]=i=1;i<=MN;++i)p2[i]=(p2[i-1]<<1)%MOD;
	for(r2[0]=i=1;i<=MN;++i)r2[i]=(r2[i-1]*((MOD+1LL)>>1))%MOD;
	for(pw[0]=i=1;i<7;++i)pw[i]=pw[i-1]*10;
	for(i=MN;i--;){solve1(i,i,0,-1);while(a[i]--)s[i]+=data(i,1LL*i*i%MOD,1);}
	for(i=1;i<MN;++i)solve2(i,i,0,1),ans^=1LL*i*s[i].s2;
	printf("%I64d",ans);
}