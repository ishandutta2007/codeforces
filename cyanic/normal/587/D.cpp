//+ 3h+ QwQ..
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

void GG(){ puts("No"),exit(0); }
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
const int inf=1e9+9;
struct edge{
	int u,v,c,w;
}e[N];
int vis[N],n,m,cnt;
map<int,int> cur;
vector<pii> t[N];
vi g[N],pt;

namespace OwO{
	vi c[N],l[N],tmp,ans; int cc,cl;
	int bas[N],now[N],vis[N],cnt;
	int loop[N],inl[N],fa[N],from[N],tot,cntv,cnte;
	vector<pii> t[N],T[N];
	#define doit(c,s) for(int k=s;k<c[i].size();k+=2)\
						ans.pb(c[i][k])
	void dfs(int u){
		vis[u]=1;
		cntv++,cnte+=t[u].size();
		int f=fa[u];
		for(auto v:t[u])
			if(!vis[v.fi]){
				fa[v.fi]=u;
				from[v.fi]=v.se;
				dfs(v.fi);
			}
			else if(v.fi==f)f=0;
			else{
				tot=0;
				loop[++tot]=v.se;
				inl[v.fi]=1,tmp.pb(v.fi);
				for(int x=u;x!=v.fi;x=fa[x]){
					loop[++tot]=from[x];
					inl[x]=1,tmp.pb(x);
				}
			}
	}
	void push(int i){
		if(i>0){
			doit(l,1);
			return;
		}
		i*=-1;
		doit(l,0);
	}
	void print(int u,int fa){
		for(auto v:t[u])
			if(v.fi!=fa&&!inl[v.fi]){
				push(v.se);
				print(v.fi,u);
			}
	}
	struct tr{int a,b,c;};
	bool Bfs(int s,int ff){
		static int q[N],fro[N];
		int l=0,r=0;q[r++]=s;
		fro[s]=0;
		while(l<r){
			int u=q[l++];
			for(auto v:T[u]){
				if(fro[u]==v.se)continue;
				if(now[v.fi])return 0;
				now[v.fi]=1,q[r++]=v.fi;
				fro[v.fi]=-v.se;
				if(ff)push(v.se);
			}
		}
		return 1;
	}
	bool chk(int lim,int ff){
		cnt=0;
		if(ff)ans.clear();
		rep(i,1,n)now[i]=bas[i];
		rep(i,1,cc){
			int A=0,B=0;
			for(int k=0;k<c[i].size();k+=2){
				A=max(A,e[c[i][k]].w);
				B=max(B,e[c[i][k+1]].w);
			}
			if(A>lim&&B>lim)return 0;
			if(ff&&A<=lim) doit(c,0);
			else if(ff&&B<=lim) doit(c,1);
		}
		rep(i,1,cl)if(l[i].size()&1){
			int A=0,B=0;
			for(int k=0;k<l[i].size();k+=2){
				A=max(A,e[l[i][k]].w);
				if(k+1<l[i].size())B=max(B,e[l[i][k+1]].w);
			}
			if(A>lim&&B>lim)return 0;
			if(B<=lim){ if(ff)doit(l,1); }
			else{
				int fir=e[l[i][0]].u;
				int las=e[l[i].back()].v;
				if(now[fir]||now[las])return 0;
				now[fir]=now[las]=1;
				if(ff)doit(l,0);
			}
		}
		rep(i,1,n)vis[i]=inl[i]=0,t[i].clear(),T[i].clear();
		vector<tr> Tmp;
		rep(i,1,cl)if(l[i].size()%2==0){
			int A=0,B=0;
			for(int k=0;k<l[i].size();k+=2){
				A=max(A,e[l[i][k]].w);
				B=max(B,e[l[i][k+1]].w);
			}
			if(A>lim&&B>lim)return 0;
			int fir=e[l[i][0]].u;
			int las=e[l[i].back()].v;
			int X=(A<=lim&&!now[fir]);
			int Y=(B<=lim&&!now[las]);
			if(X&&Y){
				Tmp.pb((tr){i,fir,las});
				T[fir].pb(mp(las,i));
				T[las].pb(mp(fir,-i));
			}
			else if(X){
				now[fir]=1;
				if(ff)doit(l,0);
				if(!Bfs(fir,ff))return 0;
			}
			else if(Y){
				now[las]=1;
				if(ff)doit(l,1);
				if(!Bfs(las,ff))return 0;
			}
			else return 0;
		}
		for(auto x:Tmp)
			if(!now[x.b]&&!now[x.c]){
				t[x.b].pb(mp(x.c,x.a));
				t[x.c].pb(mp(x.b,-x.a));
			}
		rep(i,1,n)
			if(!vis[i]&&t[i].size()){
				cntv=cnte=fa[i]=from[i]=0;
				tmp.clear(),dfs(i);
				if(cnte>2*cntv)return 0;
				if(!ff)continue;
				if(cnte==2*cntv-2)print(i,0);
				else{
					rep(i,1,tot)push(loop[i]);
					for(auto x:tmp)print(x,0);
				}
			}
		return 1;
	}
	
	void rmain(){
		memset(bas,0,sizeof bas);
		rep(i,1,cc){
			if(c[i].size()&1)GG();
			for(auto k:c[i])++bas[e[k].u];
		}
		rep(i,1,cl){
			for(int k=0;k+1<l[i].size();k++)
				++bas[e[l[i][k]].v];
		}
		rep(i,1,n)
			if(bas[i]>=2)GG();
		int l=0,r=inf,mi;
		while(l<r){
			mi=(l+r)>>1;
			if(chk(mi,0))r=mi;
			else l=mi+1;
		}
		if(l==inf)GG();
		puts("Yes");
		chk(l,1);
		printf("%d %d\n",l,(int)ans.size());
		for(auto x:ans)	printf("%d ",x);
		puts("");
	}
}

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(e[i].u),read(e[i].v);
		read(e[i].c),read(e[i].w);
		if(!cur[e[i].c])e[i].c=cur[e[i].c]=++cnt;
		else e[i].c=cur[e[i].c];
		g[e[i].c].pb(i);
	}
	rep(i,1,cnt){
		pt.clear();
		for(auto k:g[i]) pt.pb(e[k].u),pt.pb(e[k].v);
		sort(pt.begin(),pt.end());
		pt.erase(unique(pt.begin(),pt.end()),pt.end());
		for(auto x:pt){
			t[x].clear();
			vis[x]=0;
		}
		for(auto k:g[i]){
			t[e[k].u].pb(mp(e[k].v,k));
			t[e[k].v].pb(mp(e[k].u,k));
		}
		for(auto x:pt)
			if(t[x].size()>=3)GG();
		for(auto x:pt)
			if(!vis[x]&&t[x].size()==1){
				int las=x,p=t[x][0].fi; vis[las]=1;
				vi owo(1,t[x][0].se);
				int kk=t[x][0].se;
				if(e[kk].u!=x)swap(e[kk].u,e[kk].v);
				while(!vis[p]){
					vis[p]=1;
					if(t[p].size()==1)break;
					int o=(las==t[p][0].fi);
					owo.pb(t[p][o].se);
					int kk=t[p][o].se;
					if(e[kk].u!=p)swap(e[kk].u,e[kk].v);
					las=p,p=t[p][o].fi;
				}
				if(owo.size()>=2)OwO::l[++OwO::cl]=owo;
			}
		for(auto x:pt)
			if(!vis[x]&&t[x].size()==2){
				int las=x,p=t[x][0].fi; vis[las]=1;
				vi owo(1,t[x][0].se);
				int kk=t[x][0].se;
				if(e[kk].u!=x)swap(e[kk].u,e[kk].v);
				while(!vis[p]){
					vis[p]=1;
					int o=(las==t[p][0].fi);
					owo.pb(t[p][o].se);
					int kk=t[p][o].se;
					if(e[kk].u!=p)swap(e[kk].u,e[kk].v);
					las=p,p=t[p][o].fi;
				}
				OwO::c[++OwO::cc]=owo;
			}
	}
	OwO::rmain();
	return 0;
}