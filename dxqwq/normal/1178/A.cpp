#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
struct node
{
	int x,y;
}a[1003];
bool cmp(node p,node q)
{
	return p.x<q.x;
}
int main()
{
	int n=read(),tot=0;
	for(int i=1; i<=n; i++) a[i].x=read(),a[i].y=i,tot+=a[i].x;
	sort(a+2,a+n+1,cmp);
	int k=a[1].x,l=1;
	for(int i=2; i<=n; i++) if(a[i].x*2>a[1].x) break; else ++l,k+=a[i].x;
	if(k*2<=tot) return 0&puts("0"); else printf("%d\n",l);
	for(int i=1; i<=l; i++) printf("%d ",a[i].y);
	return 0;
}