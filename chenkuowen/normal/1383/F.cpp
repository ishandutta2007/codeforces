#pragma optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=5+1e4;
namespace IO{
	const int sz=1<<20;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
//		return getchar();
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& x){
		x=0; char c=gc(); int f=1;
		for(;c<'0'||c>'9';c=gc())
			if(c=='-') f=-1;
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
		x*=f;
	}
	inline void get_s(char* s){
		char c=gc();
		for(;c<'A'||c>'Z';c=gc());
		for(;c>='A'&&c<='Z';c=gc())
			*s++=c;
		*s='\0';
	}
	inline void flush(){ fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> inline void pi(T x,char c='\n'){
		if(x<0) pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f;
}
using IO::gi;
using IO::pi;
struct Graph{
	struct Edge{ int to,nxt; short c; }edge[N*2];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,short c){
		edge[++top]=(Edge){y,head[x],c};
		head[x]=top;
	}
}G;
inline void add2(int x,int y,int c){
	G.add(x,y,c); G.add(y,x,0);
}
struct TI{
	struct K{ short* x,y; }p[(int)2e6+5];
	int tp;
	TI(){tp=0; }
	inline void add(short& x){
		p[tp++]=(K){&x,x};
	}
	inline size_t size(){ return tp; }
	inline void back(size_t sz){
		while(tp>sz){
			--tp;
			*p[tp].x=p[tp].y;
		}
	}
}ti;
struct E{ int x,y,c; };
vector<E> e;
namespace FLOW{
	int iter[N],q[N],left,right;
	short lev[N];
	short dfs(int x,const int& o,short mi){
		if(x==o) return mi;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]==lev[x]+1){
				short d=dfs(y,o,min(mi,G.edge[j].c));
				if(d>0){
					ti.add(G.edge[j].c);
					ti.add(G.edge[j^1].c);
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}
			}
		}
		return 0;
	}
	inline bool bfs(int s,int t,int n){
		memset(lev,0,sizeof(short)*(n+1));
		memcpy(iter,G.head,sizeof(int)*(n+1));
		left=right=0; q[right++]=s; lev[s]=1;
		while(left!=right){
			int x=q[left++]; if(x==t) return true;
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[right++]=y;
				}
			}
		}
		return false;
	}
	int max_flow(int s,int t,int n,int mx){
		int ret=0,d;
		while(bfs(s,t,n)){
			while((d=dfs(s,t,25))!=0)
				ret+=d;
		}
		return ret;
	}
	bool vis[N];
	short dfs2(int x,const int& o,short mi){
		if(x==o) return mi;
		vis[x]=1;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&!vis[y]){
				short d=dfs2(y,o,min(mi,G.edge[j].c));
				if(d>0){
					ti.add(G.edge[j].c);
					ti.add(G.edge[j^1].c);
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}
			}
		}
		return 0;
	}
	inline int max_flow2(int s,int t,int n,int mx){
		int ret=0,d;
		while(1){
			memset(vis,0,sizeof(bool)*(n+1));
			d=dfs2(s,t,mx-ret);
			if(d>0) ret+=d;
			else break;
		}
		return ret;
	}
}
int ans[1<<10|5],n,k,mxf=0;
double g1[15],g2[15];
void dfs(int sta,int i){
	if(i==e.size()){
		ans[sta]=mxf;
		return;
	}
	dfs(sta,i+1);
	size_t sz=ti.size();
	ti.add(G.edge[i+i].c);
	G.edge[i+i].c=25;
	if(g1[i]==0){
		clock_t ss=clock();
		mxf+=FLOW::max_flow(1,n,n,25);
		g1[i]=clock()-ss;
	}else if(g2[i]==0){
		clock_t ss=clock();
		mxf+=FLOW::max_flow2(1,n,n,25);
		g2[i]=clock()-ss;
	}else if(g1[i]<g2[i]){
		mxf+=FLOW::max_flow(1,n,n,25);
	}else{
		mxf+=FLOW::max_flow2(1,n,n,25);
	}
	dfs(sta|(1<<i),i+1);
	int ff=G.edge[i+i+1].c;
	mxf-=ff;
	ti.back(sz);
}
int key[1<<10|5],sum[1<<10|5];
int main(){
	for(int i=0;i<10;++i) key[1<<i]=i;
	int m,q; gi(n); gi(m); gi(k); gi(q);
	for(int i=0;i<m;++i){
		int x,y,w; gi(x); gi(y); gi(w);
		if(i<k) e.push_back((E){x,y,w});
		add2(x,y,w);
	}
	mxf=FLOW::max_flow(1,n,n,(int)1e9);
	dfs(0,0);
//	for(int i=0;i<1<<k;++i) printf("(%d %d)",i,ans[i]);
	while(q--){
		vector<int> w(k);
		for(int i=0;i<w.size();++i) 
			gi(w[i]);
		int all=(1<<k)-1;
		sum[0]=0; int ret=ans[all];
		for(int sta=1;sta<1<<k;++sta){
			sum[sta]=sum[sta-(sta&-sta)]+w[key[sta&-sta]];
			ret=min(ret,sum[sta]+ans[all-sta]);
		}
		pi(ret);
	}
	return 0;
}