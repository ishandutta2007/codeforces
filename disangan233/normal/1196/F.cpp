// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
#define in inline
inline char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getchar()
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=2e5+5;
const ll inf=1e18;
#define pii pair<int,int> 
#define sc second 
#define fr first
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define pb push_back
vector<ll>ans;
vector<int>id(N),ine(N);
vector<vector<pii>>vec(N);
vector<pair<int,pii>>ed;
int n,m,k,num;
struct did{
	int d,u;
	did() {}
	did(re x,re y): d(x),u(y) {}
	in bool operator <(did x) const {return d>x.d;}
};
in void dijkstra(re st) 
{
	vector<ll>dis(num,inf);vector<int>vis(num);
	dis[id[st]]=0;
	priority_queue<did>q;q.ep(0,st);
	while(!q.empty())
	{
  		re x=q.top().u,u=id[x];q.pop();
  		if(!vis[u]) 
		{
			vis[u]=1;
			for(auto e:vec[x]) 
			{
				re v=id[e.fr];ll w=e.sc;
	  			if(ine[e.fr]&&dis[v]>dis[u]+w) 
				dis[v]=dis[u]+w,q.ep(dis[v],e.fr);
  			}
  		}
	}
	for(re i=id[st]+1;i<num;i++) 
  	if(dis[i]!=inf) ans.pb(dis[i]);
};
int main()
{
	n=read(),m=read(),k=read();
	for(re i=0;i<m;i++)
	{
		re x=read()-1,y=read()-1,z=read();
		vec[x].eb(y,z);vec[y].eb(x,z);
		ed.eb(z,mp(x,y));
	} 
	sort(ed.begin(),ed.end());
	for(re i=0;i<min(m,k);i++) ine[ed[i].sc.fr]=ine[ed[i].sc.sc]=1;
	for(re i=0;i<n;i++) if(ine[i]) id[i]=num++;
	for(re i=0;i<n;i++) if(ine[i]) dijkstra(i);
	sort(ans.begin(),ans.end());
	cout<<ans[k-1]<<endl;
 	return 0;
}