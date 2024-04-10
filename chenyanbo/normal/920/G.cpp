#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
//0123 50 5
int u,k,op,tot,G,h[50],t,pr[1000050],pri[1000060],o,ans,l,r,x,p;

void dfs(int p, int v, int c)
{
	if(p>tot){
		op+=c*G/v;
		return;
	}
	dfs(p+1,v,c);
	dfs(p+1,v*h[p],-c);
}

//; //inline  //dfs  //no//
inline int que(int p){
	op=0; G=p;
	dfs(1,1,1);
	return op;
}

int main()
{
	t=read();
	for(int i=2; i<=1000000; ++i){  
		if(!pr[i])pr[i]=pri[++tot]=i;
		for(int j=1; j<=tot; ++j){
			if(i*pri[j]>1000000)break;
			pr[i*pri[j]]=pri[j];
			if(!(i%pri[j]))break;
		}
	}
	while(t--){
		x=read(); p=read(); k=read(); tot=0;
		while(p>1){
			h[++tot]=u=pr[p];
			while(!(p%u))p/=u;
		}
		k+=que(x);
		l=2; r=10000000; //s
		while(l<=r){
			int mid=(l+r)>>1;
			o=que(mid);
			if(o>=k)ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
}