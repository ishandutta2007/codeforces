#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+3e5;
struct DSF{
	int fa[MAX_N],p[MAX_N],sz0[MAX_N],sz1[MAX_N],ans;
	DSF(){ ans=0; }
	void ms(int x){ fa[x]=x,p[x]=0,sz0[x]=x>0,sz1[x]=0; }
	int fs(int x){
		if(fa[x]!=x){
			int y=fa[x];
			fa[x]=fs(fa[x]);
			p[x]^=p[y];
		}
		return fa[x];
	}
	int gk(int x){ fs(x); return p[x]; }
	bool mb(int x,int y){
		return fs(x)==fs(y);
	}
	void merge(int x,int y,int t){
//		printf("(%d %d %d)\n",x,y,t);
		if(mb(x,y)){
//			printf("(%d %d %d)\n",x,y,t);
			if((gk(x)^gk(y))!=t) assert(0);
			return;
		}
		if(fs(y)==0) swap(x,y);
		ans-=gsz(x);
		ans-=gsz(y);
		t^=gk(x)^gk(y);
		x=fs(x),y=fs(y);
		fa[y]=x;  p[y]=t;
		if(t==0){
			sz0[x]+=sz0[y];
			sz1[x]+=sz1[y];
		}else{
			sz0[x]+=sz1[y];
			sz1[x]+=sz0[y];
		}
		ans+=gsz(x);
	}
	int gsz(int x){
		x=fs(x);
		return x==0?sz1[x]:min(sz0[x],sz1[x]);
	}
	void print(int n){
		printf("<%d>",fs(0));
		for(int i=0;i<=n;++i) 
			if(i==fs(i))
				printf("|%d %d %d|",i,sz0[i],sz1[i]);
	}
}dsf;
vector<int> g[MAX_N];
char s[MAX_N];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;++i){
		int tp; scanf("%d",&tp);
		for(int j=1;j<=tp;++j){
			int pos; scanf("%d",&pos);
			g[pos].push_back(i);
		}
	}
	for(int i=0;i<=m;++i) dsf.ms(i);
	int ans=0;
	for(int i=1;i<=n;++i){
		if(g[i].size()==1){
			dsf.merge(0,g[i][0],!(s[i]-'0'));
		}else if(g[i].size()>1){
			dsf.merge(g[i][0],g[i][1],!(s[i]-'0'));
		}
		printf("%d\n",dsf.ans);
//		dsf.print(m);
	}
	return 0;
}