#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int o=1.5e6;
int n1,n2,m,Q,h[o],cnt=1,S,T,d[o],cur[o],st1[o],st2[o],tp;long long ans;queue<int> q;
struct Edge{int v,p,c;}e[o];
inline void ad(int U,int V,int C){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].c=C;}
inline void add(int ST,int ED,int CA){ad(ST,ED,CA);ad(ED,ST,0);}
inline bool bfs(){
	for(int i=S;i<=T;d[i++]=0) cur[i]=h[i];
	for(q.push(S),d[S]=1;!q.empty();q.pop()) for(int i=h[q.front()];i;i=e[i].p)
		if(e[i].c&&!d[e[i].v]) d[e[i].v]=d[q.front()]+1,q.push(e[i].v);
	return d[T];
}
int dfs(int A,int B){
	if(A==T||!B) return B;
	int x,res=0;
	for(int&i=cur[A];i;i=e[i].p) if(e[i].c&&d[A]+1==d[e[i].v])
		{x=dfs(e[i].v,min(B-res,e[i].c));e[i].c-=x;e[i^1].c+=x;if((res+=x)==B) return B;}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n1,&n2,&m,&Q);T=n1+n2+1;
	for(int i=1,x,y;i<=m;++i) scanf("%d%d",&x,&y),add(x,y+n1,1);
	for(int i=1;i<=n1;++i) add(S,i,1);
	for(int i=1;i<=n2;++i) add(i+n1,T,1);
	for(;bfs();dfs(S,o));
	for(int i=1;i<=n1;++i) if(!d[i]){
		st1[++tp]=i;
		for(int j=h[i];j;j=e[j].p) if(j/2<=m&&!e[j].c) st2[tp]=j/2;
	}
	for(int i=1;i<=n2;++i) if(d[i+n1]){
		st1[++tp]=-i;
		for(int j=h[i+n1];j;j=e[j].p) if(j/2<=m&&e[j].c) st2[tp]=j/2;
	}
	for(int i=1;i<=tp;++i) ans+=st2[i];
	for(int opt;Q--;cout<<endl){
		scanf("%d",&opt);
		if(opt==1) cout<<"1\n"<<st1[tp]<<"\n",cout<<(ans-=st2[tp--]);
		else{
			cout<<tp<<"\n";
			for(int i=1;i<=tp;++i) cout<<st2[i]<<" ";
		}
	}
	return 0;
}