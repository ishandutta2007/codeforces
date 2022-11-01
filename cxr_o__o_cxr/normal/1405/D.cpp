//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define re register
const int N=1e5+4;
int n,A,B,da,db,s,t,d[N];
vector<int>e[N];
queue<int>q;
inline int findfar(int st){
	memset(d,0x3f,sizeof(int)*(n+1));
	d[st]=0;
	q.push(st);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto v:e[x])if(d[v]>d[x]+1){
			d[v]=d[x]+1;
			q.push(v);
		}
	}
	int ret=1;
	for(re int i=2;i<=n;++i)
		if(d[i]>d[ret])ret=i;
	return ret;
}
int main(){
	for(re int T=read(),u,v;T--;){
		n=read();A=read();B=read();da=read();db=read(); 
		for(int i=1;i<=n;i++)e[i].clear();
		for(re int i=1;i<n;++i){
			u=read();v=read();
			e[u].push_back(v);e[v].push_back(u);
		}
		if(db<=(da<<1)){puts("Alice");continue;}
		s=findfar(A);
		if(d[B]<=da){puts("Alice");continue;}
		t=findfar(s);
		if(d[t]<=(da<<1)){puts("Alice");continue;}
		puts("Bob");
	}
	return (0-0);
}