#include<bits/stdc++.h>
#define pi pair<int,int>
#define emp (node){0,0,0}
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{int l,r,len;}a[4000003];
char s[1000003];
inline void build(int l,int r,int id)
{
	if(l==r) 
	{
		if(s[l]=='(') a[id].r=1;
		else a[id].l=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	a[id].len=a[id<<1].len+a[(id<<1)+1].len,a[id].l=a[id<<1].l,a[id].r=a[(id<<1)+1].r;
	if(a[id<<1].r<a[(id<<1)+1].l) a[id].len+=a[id<<1].r*2,a[id].l+=a[(id<<1)+1].l-a[id<<1].r; 
	else a[id].len+=a[(id<<1)+1].l*2,a[id].r+=a[id<<1].r-a[(id<<1)+1].l; 
	return ;
}
node query(int l,int r,int L,int R,int id)
{
	if(r<L || R<l) return emp;
	if(L<=l && r<=R) return a[id];
	int mid=(l+r)>>1;
	node lans=query(l,mid,L,R,id<<1),rans=query(mid+1,r,L,R,(id<<1)+1),ans=emp;
	ans.len=lans.len+rans.len,ans.l=lans.l,ans.r=rans.r;
	if(lans.r<rans.l) ans.len+=lans.r*2,ans.l+=rans.l-lans.r; 
	else ans.len+=rans.l*2,ans.r+=lans.r-rans.l; 
	return ans;
}
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),m=read();
	build(1,n,1);
	for(int l,r;m--;) l=read(),r=read(),printf("%d\n",query(1,n,l,r,1).len);
	return 0;
}