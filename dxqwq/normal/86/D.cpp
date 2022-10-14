#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int l,r,index;
};
int bl;
bool cmp(node x,node y)
{
	if(x.l/bl!=y.l/bl) return x.l<y.l;
	return x.r<y.r;
}
using namespace std;
int a[1000003];
int now[1000003],l=1,r=1;
node q[1000003];
long long ans[1000003];
int main()
{
	int n=read(),m=read();bl=sqrt(n)+1;
	for(int i=1; i<=n; i++) a[i]=read();
	++now[a[1]];
	for(int i=1; i<=m; i++) q[i].l=read(),q[i].r=read(),q[i].index=i;
	sort(q+1,q+m+1,cmp);
	long long Ans=a[1]; 
	for(int i=1; i<=m; i++) 
	{
		while(l>q[i].l) --l,Ans+=1ll*(((now[a[l]]++)<<1)+1)*a[l];
		while(l<q[i].l) Ans-=1ll*a[l]*(((--now[a[l]])<<1)+1),++l;
		while(r>q[i].r) Ans-=1ll*a[r]*(((--now[a[r]])<<1)+1),--r;
		while(r<q[i].r) ++r,Ans+=1ll*(((now[a[r]]++)<<1)+1)*a[r];
		ans[q[i].index]=Ans;
	}
	for(int i=1; i<=m; i++) printf("%lld\n",ans[i]); 
	return 0;
}