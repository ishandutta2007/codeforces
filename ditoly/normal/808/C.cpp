#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100
int a[MN+5],b[MN+5],c[MN+5];
bool cmp(int x,int y){return a[x]>a[y];}
int main()
{
	int n,w,i;
	n=read();w=read();
	for(i=1;i<=n;++i)a[i]=read(),w-=b[i]=a[i]+1>>1,c[i]=i;
	if(w<0)return 0*puts("-1");
	sort(c+1,c+n+1,cmp);
	while(w)for(i=1;w&&i<=n;++i)if(b[c[i]]<a[c[i]])++b[c[i]],--w;
	for(i=1;i<=n;++i)printf("%d ",b[i]);
}