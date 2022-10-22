#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,u[500004],v[500004];
ll ans;
int val[750004],dat[750004],tg[750004],sz[750004],a[750004];
bool rev[750004];
int f[750004],s[2][750004];
bool get(int x){return s[1][f[x]]==x;}
bool isntroot(int x){return s[0][f[x]]==x||s[1][f[x]]==x;}
void pushup(int x){dat[x]=max(val[x],max(dat[s[0][x]],dat[s[1][x]])),sz[x]=sz[s[0][x]]+sz[s[1][x]]+a[x];}
void push(int x,int v){if(v==-1)val[x]=dat[x]=0;else{if(x>n)val[x]=dat[x]=v;else if(sz[x])dat[x]=v;}tg[x]=v;}
void pushdown(int x){
	if(rev[x]){swap(s[0][x],s[1][x]);if(s[0][x])rev[s[0][x]]^=1;if(s[1][x])rev[s[1][x]]^=1;rev[x]=0;}
	if(tg[x]!=0){if(s[0][x])push(s[0][x],tg[x]);if(s[1][x])push(s[1][x],tg[x]);tg[x]=0;}
}
void rotate(int x){
	int y=f[x],z=f[y];bool typ=get(x);s[typ][y]=s[typ^1][x];
	if(s[typ^1][x])f[s[typ^1][x]]=y;s[typ^1][x]=y;if(isntroot(y))s[get(y)][z]=x;
	f[x]=z,f[y]=x,pushup(y),pushup(x);
}
stack<int>st;
void splay(int x){
	int y=x;st.push(y);while(isntroot(y))y=f[y],st.push(y);
	while(!st.empty())pushdown(st.top()),st.pop();
	for(int fa;fa=f[x],isntroot(x);rotate(x))
		if(isntroot(fa))rotate(get(x)==get(fa)?fa:x);
}
void access(int x){for(int y=0;x;y=x,x=f[x])splay(x),s[1][x]=y,pushup(x);}
void makeroot(int x){access(x),splay(x),rev[x]^=1;}
int findroot(int x){access(x),splay(x);while(1){pushdown(x);if(s[0][x])x=s[0][x];else break;}splay(x);return x;}
void split(int x,int y){makeroot(x),access(y),splay(y);}
void link(int x,int y){makeroot(x),f[x]=y;}
void cut(int x,int y){split(x,y);f[x]=s[0][y]=0;pushup(y);}
bool conn(int x,int y){makeroot(x);return x==findroot(y);}
int qry(int x,int y){split(x,y);return dat[y];}
void asgn(int x,int y,int tag){split(x,y),push(y,tag);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]),a[i+n]=1;
	int pts=0;
	for(int i=1;i<=m;i++){
		if(i!=1){
			int U=u[i-1],V=v[i-1];
			int tmp=qry(U,V);
			cut(U,n+i-1),cut(V,n+i-1);
			if(tmp)link(u[tmp],n+tmp),link(v[tmp],n+tmp),asgn(U,V,-1);
		}
		while(pts<m){
			int U=u[pts+1],V=v[pts+1];
			if(!conn(U,V)){
				pts++;
				link(U,n+pts),link(V,n+pts);
				continue;
			}
			int tmp=qry(U,V);
			if(tmp!=0)break;
			pts++;
			asgn(U,V,pts);
		}
		ans+=pts-i+1;
	}
	printf("%I64d",ans);
}