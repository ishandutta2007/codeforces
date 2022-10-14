#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int x[1000003],y[1000003],cnt;
void dfs(int l,int r)
{
	if(l==r) return ;
	if(l+1==r) { x[++cnt]=l,y[cnt]=r; return; }
	int mid=(l+r)/2; 
	dfs(l,mid),dfs(mid+1,r);
	int L=l,R=r;
	while(L<R) x[++cnt]=L,y[cnt]=R,++L,--R;
}
int main()
{
	int n=read(),len=1;
	while((len<<1)<=n) len<<=1;
	dfs(1,len),dfs(n-len+1,n);
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; i++) printf("%d %d\n",x[i],y[i]);
    return 0;
}