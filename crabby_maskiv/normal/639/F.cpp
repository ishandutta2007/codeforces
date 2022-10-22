#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5;
int n,m,q;
int R;
int rotate(int element){
   element=(element+R)%n;
   if (element==0) {
       element=n;
   }
   return element;
}
vector<pii> g1[N],g3[N];
vector<int> g2[N];
int dfn[N],low[N],tot,cnt;
int ecc[N];
int stk[N],top;
bool ins[N];
void tarjan(vector<pii>* g,int u,int fid){
	dfn[u]=low[u]=++tot;
	stk[++top]=u;
	ins[u]=1;
	for(auto e:g[u]){
		int v=e.fr,id=e.sc;
		if(id==fid) continue;
		if(dfn[v]){
			if(ins[u]) low[u]=min(low[u],dfn[v]);
		}
		else {
			tarjan(g,v,id);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				cnt++;
				while(top){
					int x=stk[top--];
					ecc[x]=cnt;
					ins[x]=0;
					if(x==v) break;
				}
			}
		}
	}
}
int tmp[N];
int st[20][N<<1],lg[N<<1];
int lft[N],rgt[N],eu[N<<1],h[N],fa[N],co[N];
void dfs1(int u,int col){
	co[u]=col;
	h[u]=h[fa[u]]+1;
	lft[u]=++tot;
	eu[tot]=u;
	for(auto v:g2[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v,col);
		eu[++tot]=u;
	}
	rgt[u]=tot;
}
inline int lca(int x,int y){
	x=lft[x];y=lft[y];if(x>y) swap(x,y);
	int c=lg[y-x+1];
	if(h[st[c][x]]<h[st[c][y-(1<<c)+1]]) return st[c][x];
	else return st[c][y-(1<<c)+1];
}
int uu[N],vv[N],f[N];
inline bool cmp(int x,int y){
	return lft[x]<lft[y];
}
int rt(int u){
	if(f[u]==u) return u;
	return f[u]=rt(f[u]);
}
int main() {
	//freopen("C.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n>>m>>q;
	for(i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g1[x].push_back({y,i});
		g1[y].push_back({x,i});
	}
	for(i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(g1,i,0);
			cnt++;
			while(top){
				int x=stk[top--];
				ecc[x]=cnt;
				ins[x]=0;
			}
		}
	}
	memcpy(tmp,ecc,sizeof(ecc));
	//for(i=1;i<=n;i++) cerr<<ecc[i]<<" ";cerr<<endl;
	for(i=1;i<=cnt;i++) f[i]=i;
	for(i=1;i<=n;i++){
		for(auto e:g1[i]){
			int v=e.fr;
			if(ecc[i]!=ecc[v]) g2[ecc[i]].push_back(ecc[v]);
		}
	}
	tot=0;
	for(i=1;i<=cnt;i++)
		if(!lft[i]) dfs1(i,i);
	for(i=1;i<=tot;i++) lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	for(i=1;i<=tot;i++) st[0][i]=eu[i];
	for(j=1;j<20;j++){
		for(i=1;i+(1<<j)-1<=tot;i++){
			if(h[st[j-1][i]]<h[st[j-1][i+(1<<j-1)]]) st[j][i]=st[j-1][i];
			else st[j][i]=st[j-1][i+(1<<j-1)];
		}
	}
	for(int qq=1;qq<=q;qq++){
		int nn,mm;cin>>nn>>mm;
		vector<int> s(nn),a;
		vector<pii> e(mm);
		for(i=0;i<nn;i++){
			cin>>s[i];s[i]=rotate(s[i]);
			s[i]=tmp[s[i]];
		}
		for(i=0;i<mm;i++){
			cin>>e[i].fr>>e[i].sc;
			e[i].fr=rotate(e[i].fr);e[i].sc=rotate(e[i].sc);
			e[i].fr=tmp[e[i].fr];
			e[i].sc=tmp[e[i].sc];
		}
		for(i=0;i<nn;i++) a.push_back(s[i]);
		for(i=0;i<mm;i++){
			a.push_back(e[i].fr);
			a.push_back(e[i].sc);
		}
		sort(a.begin(),a.end(),cmp);
		a.resize(unique(a.begin(),a.end())-a.begin());
		int t=a.size();
		for(i=0;i<t-1;i++)
			if(co[a[i]]==co[a[i+1]]) a.push_back(lca(a[i],a[i+1]));
		sort(a.begin(),a.end(),cmp);
		a.resize(unique(a.begin(),a.end())-a.begin());
		t=a.size();
		for(auto x:a){
			g3[x].clear();
			dfn[x]=low[x]=ecc[x]=ins[x]=0;
		}
		top=0;
		int E=0;
		for(i=t-1;i>=0;i--){
			while(top&&lft[a[i]]<=lft[stk[top]]&&rgt[a[i]]>=rgt[stk[top]]){
				g3[a[i]].push_back({stk[top],++E});
				g3[stk[top]].push_back({a[i],E});
				top--;
			}
			stk[++top]=a[i];
		}
		for(auto x:e){
			g3[x.fr].push_back({x.sc,++E});
			g3[x.sc].push_back({x.fr,E});
		}
		tot=cnt=top=0;
		for(auto x:a){
			if(!dfn[x]){
				tarjan(g3,x,0);
				cnt++;
				while(top){
					int x=stk[top--];
					ins[x]=0;
					ecc[x]=cnt;
				}
			}
		}
		int ans=1;
		for(i=1;i<s.size();i++)
			if(ecc[s[i]]!=ecc[s[i-1]]) ans=0;
		cout<<(ans?"YES":"NO")<<endl;
		R=(R+ans*qq)%n;
	}
	return 0;
}