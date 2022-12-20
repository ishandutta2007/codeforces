#include<bits/stdc++.h>
#define N 1050500
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int op,l,r,ll,u,t,tot,m,a[N],n,ma[N],f[N],pr[N],pri[N];
long long s[N]; 

#define ls (p<<1)
#define rs ((p<<1)|1)
void build(int p, int l, int r){
	if(l==r){
		s[p]=ma[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	ma[p]=max(ma[ls],ma[rs]);
	s[p]=s[ls]+s[rs];
}

void modi(int p, int l, int r, int x, int y){ 
	if(ma[p]<=2)return;
	if(l==r)
	{
	    s[p]=ma[p]=f[s[p]];
	    return;
	}
	int mid=(l+r)>>1;
	if(y<=mid)modi(ls,l,mid,x,y);
	else if(x>mid)modi(rs,mid+1,r,x,y);
	else modi(ls,l,mid,x,mid),modi(rs,mid+1,r,mid+1,y);  
	ma[p]=max(ma[ls],ma[rs]);
	s[p]=s[ls]+s[rs];
}

long long que(int p, int l, int r, int x, int y){  
	if(x<=l &&y>=r)return s[p];
	int mid=(l+r)>>1;
	if(y<=mid)return que(ls,l,mid,x,y);
	if(x>mid)return que(rs,mid+1,r,x,y);
	return que(ls,l,mid,x,mid)+que(rs,mid+1,r,mid+1,y);
}

int main()
{
//	freopen("1.in","r",stdin);
	n=read(); m=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	
	for(int i=2; i<=1000000; ++i){  
		if(!pr[i])pr[i]=pri[++tot]=i;
		for(int j=1; j<=tot; ++j){
			if(i*pri[j]>1000000)break;
			pr[i*pri[j]]=pri[j];
			if(!(i%pri[j]))break;
		}
	}
	f[1]=1;
	for(int i=2; i<=1000000; ++i){
		if(pr[i]==i)f[i]=2;
		else{
			u=i/pr[i];
			t=1;
			while(!(u%pr[i])){
				u/=pr[i];
				++t;
			}
			//v
			f[i]=f[i/pr[i]]+f[i/pr[i]]/t;
		}
	}
	build(1,1,n);
	
	while(m--){
		op=read(); l=read(); r=read();
		if(op==1){
			modi(1,1,n,l,r);
			continue;
		}
		printf("%I64d\n",que(1,1,n,l,r));
	}
}