#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10,INF=1e9;
int n,m,u[MAXN],v[MAXN],w[MAXN];
int fa[MAXN];
int lvl[MAXN],dis1[MAXN],dis2[MAXN];
pi pre[MAXN];
int ord[MAXN],tot;
pi rk[MAXN];
pp tmp[MAXN];
vector<pi>e1[MAXN],e2[MAXN];
vector<int>node[MAXN];
vector<int>num,ret;
queue<int>q;
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
bool cmp(pp& p1,pp& p2){
	if(p1.se.fr!=p2.se.fr)return p1.se.fr<p2.se.fr;
	else if(p1.fr.se!=p2.fr.se)return p1.fr.se<p2.fr.se;
	else return p1.se.se<p2.se.se;
}
void update(pp& p,int rk,int w,int len){
	if(rk<p.se.fr){p.fr.se=w;p.se.fr=rk;p.se.se=len;
		return;
	}
	if(rk>p.se.fr)return;
	if(w<p.fr.se){p.fr.se=w;p.se.se=len;
		return;
	}
	if(w>p.fr.se)return;
	if(len<p.se.se)p.se.se=len;
}
void solve(int d){
	tot=node[d].size();
	rep(i,1,tot){ord[node[d][i-1]]=i;tmp[i]=mp(mp(node[d][i-1],INF),mp(INF,INF));}
	for(auto u:node[d-1]){
		for(auto V:e1[u]){
			int v=V.fr,w=V.se;if(lvl[v]!=d)continue;
			update(tmp[ord[v]],rk[u].fr,w,rk[u].se);
		}
	}
	for(auto u:node[d-1]){
		for(auto V:e1[u]){
			int v=V.fr,w=V.se;if(lvl[v]!=d)continue;
			pp& info=tmp[ord[v]];
			if(rk[u].fr==info.se.fr && w==info.fr.se && rk[u].se==info.se.se){
				pre[v].fr=u;
				pre[v].se=w;
			}
			
		}
	} 
	sort(tmp+1,tmp+tot+1,cmp);
	rk[tmp[1].fr.fr].fr=1;rk[tmp[1].fr.fr].se=tmp[1].se.se;
	rep(i,2,tot){
		rk[tmp[i].fr.fr].fr=rk[tmp[i-1].fr.fr].fr+1;
		rk[tmp[i].fr.fr].se=tmp[i].se.se;
		pp& now=tmp[i],lst=tmp[i-1];
		if(lst.fr.se==now.fr.se && lst.se.fr==now.se.fr && lst.se.se==now.se.se)rk[tmp[i].fr.fr].fr--;
	}
}
void output(){
	int u=1;
	while(u!=n){
		ret.pb(u);
		num.pb(pre[u].se);
		u=pre[u].fr;
	}
	ret.pb(n);
	reverse(num.begin(),num.end());
	int flag=1;
	for(auto u:num){
		if(u==0){
			if(!flag)printf("%d",u);
		}else{
			flag=0;printf("%d",u);
		}
	}
	if(flag)printf("0");printf("\n");
	printf("%d\n",(int)ret.size());
	for(auto u:ret)printf("%d ",u-1);printf("\n");
}
int main(){
	cin>>n>>m;
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		cin>>u[i]>>v[i]>>w[i];
		u[i]++;v[i]++;
		if(w[i]==0){
			if(Find(u[i])!=Find(v[i]))fa[Find(u[i])]=Find(v[i]);
			e2[u[i]].pb(mp(v[i],0));e2[v[i]].pb(mp(u[i],0));	
		}
		e1[u[i]].pb(mp(v[i],w[i]));e1[v[i]].pb(mp(u[i],w[i]));
	}
	rep(i,1,n)dis1[i]=lvl[i]=INF,rk[i]=mp(INF,INF);dis1[n]=0;q.push(n);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto V:e2[u]){
			int v=V.fr;
			if(dis1[v]>dis1[u]+1){
				dis1[v]=dis1[u]+1;
				pre[v].fr=u;
				q.push(v);
			}
		}
	}
	rep(i,1,n){if(dis1[i]!=INF)q.push(i),lvl[i]=0;}
	while(q.size()){
		int u=q.front();q.pop();
		for(auto V:e1[u]){
			int v=V.fr;
			if(lvl[v]==INF){
				lvl[v]=lvl[u]+1;
				q.push(v);
			}
		}	
	}
	rep(i,1,n)if(lvl[i]!=INF)node[lvl[i]].pb(i);
	rep(i,1,n){
		if(lvl[i]==0){
			rk[i].fr=1;rk[i].se=dis1[i];
		}
	}
	rep(i,1,n)solve(i);
	output();
	return 0;
}