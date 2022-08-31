#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,_,q,i,j,dfn[300005],low[300005],col[300005],vis[300005],cnt,sft,ti,rt[300005],lst[300005];
int fa[300005][19],dep[300005],pa[300005],px[300005],py[300005],col2[300005],dfn2[300005],tot;
int stk[300005],tp;
vector<pair<int,int> > bi[300005],bi3[300005];
vector<int> bi2[300005],a,all;
stack<int> stkk;
bool cmp(int x,int y)
{
	return dfn2[x]<dfn2[y];
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++ti;
	stkk.push(x);
	ff(bi[x],it)if(it->second!=fa){
		if(!dfn[it->first]){
			tarjan(it->first,it->second);
			low[x]=min(low[x],low[it->first]);
		}
		else{
			low[x]=min(low[x],dfn[it->first]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		while(stkk.top()!=x){
			col[stkk.top()]=cnt;
			stkk.pop();
		}
		col[stkk.top()]=cnt;
		stkk.pop();
	}
}
void dfs1(int x,int p)
{
	fa[x][0]=p;rt[x]=i;dfn2[x]=++ti;
	ff(bi2[x],it){
		if(*it==p) continue;
		dep[*it]=dep[x]+1;
		dfs1(*it,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int i,t=dep[x]-dep[y];
	fd0g(i,18)if((t>>i)&1) x=fa[x][i];
	if(x==y) return x;
	fd0g(i,18)if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}
void add(int x,int y)
{
//	cerr<<"  "<<x<<' '<<y<<endl;
	tot++;
	bi3[x].push_back(make_pair(y,tot));
	bi3[y].push_back(make_pair(x,tot));
	all.push_back(x);
	all.push_back(y);
}
void ins(int x)
{
	if(tp<2){
		stk[++tp]=x;
		return;
	}
	int z=lca(stk[tp],x);
	if(z==stk[tp]){
		stk[++tp]=x;
		return;
	}
	while(tp>1&&dfn2[stk[tp-1]]>=dfn2[z]){
		add(stk[tp],stk[tp-1]);
		tp--;
	}
	if(stk[tp]!=z){
		add(stk[tp],z);
		stk[tp]=z;
	}
	stk[++tp]=x;
}
void tarjan2(int x,int fa)
{
	lst[x]=_;
	dfn[x]=low[x]=++ti;
	stkk.push(x);
	ff(bi3[x],it)if(it->second!=fa){
		if(lst[it->first]!=_){
			tarjan2(it->first,it->second);
			low[x]=min(low[x],low[it->first]);
		}
		else{
			low[x]=min(low[x],dfn[it->first]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		while(stkk.top()!=x){
			col2[stkk.top()]=cnt;
			stkk.pop();
		}
		col2[stkk.top()]=cnt;
		stkk.pop();
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	fz1(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		bi[x].push_back(make_pair(y,i));
		bi[y].push_back(make_pair(x,i));
	}
	fz1(i,n)if(!dfn[i]) tarjan(i,0);
	fz1(i,n) ff(bi[i],it){
		if(col[i]!=col[it->first]){
			bi2[col[i]].push_back(col[it->first]);
		}
	}
	ti=0;
	fz1(i,cnt)if(!dfn2[i]){
		dfs1(i,0);
	}
	fz1(j,18)fz1(i,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	fz1(_,q)
	{
		a.clear();all.clear();
		int qn,qm;
		scanf("%d%d",&qn,&qm);
		fz1(i,qn){
			scanf("%d",&pa[i]);
			pa[i]=(pa[i]+sft-1)%n+1; pa[i]=col[pa[i]];
			a.push_back(pa[i]);
			all.push_back(pa[i]);
		}
		fz1(i,qm){
			scanf("%d%d",&px[i],&py[i]);
			px[i]=(px[i]+sft-1)%n+1; px[i]=col[px[i]];
			py[i]=(py[i]+sft-1)%n+1; py[i]=col[py[i]];
			a.push_back(px[i]); 
			a.push_back(py[i]); 
		}
		
		sort(a.begin(),a.end(),cmp);
		a.resize(unique(a.begin(),a.end())-a.begin());
//		ff(a,it) cerr<<*it<<' ';cerr<<endl;
		fz0k(i,a.size()){
			if(i==0||stk[1]!=rt[a[i]]){
				while(tp>1){
					add(stk[tp],stk[tp-1]);
					tp--;
				}
				stk[tp=1]=rt[a[i]];
			}
			if(rt[a[i]]!=a[i]){
				ins(a[i]);
			}
		}
		while(tp>1){
			add(stk[tp],stk[tp-1]);
			tp--;
		}
		
		fz1(i,qm){
			add(px[i],py[i]);
		}
		ti=0;cnt=0;
		ff(all,it){
			if(lst[*it]!=_){
				tarjan2(*it,0);
			}
		}
		fz1(i,qn) if(col2[pa[i]]!=col2[pa[1]]){
			break;
		}
		if(i>qn){
			puts("YES");
			(sft+=_)%=n;
		}
		else{
			puts("NO");
		}
		ff(all,it) bi3[*it].clear();
	}
	return 0;
}