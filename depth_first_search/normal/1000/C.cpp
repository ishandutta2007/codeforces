#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 200000
using namespace std;
int n;
LL x[N+5],y[N+5],z[4*N+5],f[4*N+5],ans[N+5];
map<LL,LL> p,q;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') (x*=10)+=ch-'0',ch=getchar();
	return x*=f;
}
void write(LL x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) z[4*i-3]=x[i]=read(),z[4*i-2]=x[i]+1,z[4*i-1]=y[i]=read(),z[4*i]=y[i]+1;
	int w=4*n,k=0;
	sort(z+1,z+w+1);
	for(int i=1;i<=w;i++) if(z[i]!=z[i-1]||i==1) p[z[i]]=i-k,q[i-k]=z[i];else k++;
	for(int i=1;i<=n;i++) f[p[x[i]]]++,f[p[y[i]]+1]--;
	for(int i=1;i<w;i++) ans[f[i]+=f[i-1]]+=q[i+1]-q[i];
	for(int i=1;i<=n;i++) write(ans[i]),putchar(' ');
	return 0;
}