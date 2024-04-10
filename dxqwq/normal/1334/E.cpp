#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long qp(long long a,long long b){if(!b) return 1;long long w=qp(a,b>>1);w=w*w%p;return b&1?w*a%p:w;}
long long jc[103],inv[103];
long long P[23],ind[23];long long p_c=0;
map<long long,long long> f;
void dfs(long long now,long long ff,long long t,long long tt)
{
	if(now==p_c+1) {f[ff]=jc[tt]*t%p;return;}
	for(long long i=0; i<=ind[now]; i++) {dfs(now+1,ff,t*inv[i]%p,tt+i);ff*=P[now];}
}

long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
inline long long rd(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long u,v;
signed main()
{
	long long D=rd();long long d=D;long long i=3;
	long long cnt=0;
	long long q=rd();
	while(d%2==0) {d/=2;++cnt;} if(cnt) {P[++p_c]=2;ind[p_c]=cnt;}
	while(i*i<=d)
	{
		cnt=0;
		while(d%i==0) {d/=i;++cnt;} if(cnt) {P[++p_c]=i;ind[p_c]=cnt;}
		i+=2;
	}
	if(d!=1) {P[++p_c]=d;ind[p_c]=1;}
	inv[0]=jc[0]=1;for(long long i=1; i<=55; i++) {jc[i]=jc[i-1]*i%p;inv[i]=qp(jc[i],p-2);}
	dfs(1,1,1,0);
	
	while(q--)
	{
		u=rd(),v=rd();long long x=gcd(u,v);u/=x;v/=x;
		printf("%lld\n",f[u]*f[v]%p);
	}
	return 0;
}