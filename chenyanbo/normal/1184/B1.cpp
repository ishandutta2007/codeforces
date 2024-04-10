#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 100056
struct node {
	int d,g;
	
	node(){
		d=0; g=0;
	}
	
	node(int d_, int g_){
		d=d_,g=g_;
	}
	
	bool operator < (const node & a) const {
		return d<a.d;
	}
}c[N];


int s,b,a[N],f[N],l,r,ans,mi;

int main()
{
	s=read(); b=read();
	for(int i=1;i<=s;++i)a[i]=read() ;
	
	c[1]=(node){1,1};
//	if(c[1]==c[0])puts("1");
	
	for(int i=1;i<=b;++i)c[i].d=read(),c[i].g=read();// = == node
	sort(c+1,c+b+1);
	for(int i=1;i<=b;++i)f[i]=f[i-1]+c[i].g;
	for(int i=1;i<=s;++i){
		ans=0;
		l=1; r=b;
		while(l<=r){
			mi=l+r>>1;
			if(c[mi].d<=a[i])ans=mi,l=mi+1;
			else r=mi-1;
		}
		printf("%d ",f[ans]);
	}
}