#include<bits/stdc++.h>
#define N 200050
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

struct node
{
	int u, v;
	bool operator < (const node & a)const{
		if(u!=a.u)return u<a.u;
		return v<a.v;
	}
};

set<int>g;
set<node>s;
int op[N],h[N],uu,st[N],qn,n,m,o,tot,u,v,q[N];
int main()
{
	n=read(); m=read();
	for(int i=1; i<=m; ++i){
		u=read(); v=read();
		s.insert((node){u,v});
		s.insert((node){v,u});
	}
	
	for(int i=1; i<=n; ++i)g.insert(i);
	for(int i=1; i<=n; ++i)if(!op[i])
	{
		++tot; g.erase(i); op[i]=tot; uu=0;
		
		q[qn=1]=i;
		
		for(int q1=1; q1<=qn; ++q1){
			v=q[q1]; o=0;
		    for(set<int>::iterator it=g.begin(); it!=g.end(); ++it)
			{
			    u=*it;
			    if(s.find((node){v,u})==s.end()){
				    st[++o]=u;
				    q[++qn]=u;
				    ++uu;
				}
			}
			for(int i=1; i<=o; ++i)op[st[i]]=tot,g.erase(st[i]); 
		}
		h[tot]=uu+1;
		
	}
	printf("%d\n",tot);
	sort(h+1,h+tot+1);
	for(int i=1; i<=tot; ++i)printf("%d ",h[i]);
}