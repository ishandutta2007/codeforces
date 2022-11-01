#include <bits/stdc++.h>

#define rep(i,n) for(LL i=0;i<n;i++)
#define repn(i,n) for(LL i=1;i<=n;i++)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

struct edge
{
	LL to,flow,cost,rev;
	
	edge(LL a,LL b,LL c,LL d):to(a),flow(b),cost(c),rev(d){}
};

LL n,depth[10010],now[10010];
vector <edge> g[10010];
vector <pair <pii,pii> > que;
queue <LL> qq;

void add_edge(LL x,LL y,LL flow,LL cost)
{
	//cout<<x<<' '<<y<<' '<<cost<<endl; 
	g[x].pb(edge(y,flow,cost,(LL)g[y].size()));
	g[y].pb(edge(x,0,-cost,(LL)g[x].size()-1));
}

LL dist[10010],prevv[10010],preve[10010],h[10010],step[5010][5010];
bool inq[10010];
queue <LL> q;

bool relax(LL to,LL val,LL pp,LL ii)
{
  if(dist[to]>val)
  {
    dist[to]=val;
    prevv[to]=pp;
    preve[to]=ii;
    return true;
  }
  return false;
}

LL min_cost_flow(LL s,LL t,LL f)
{
	LL ret=0;
	while(f>0)
	{
		//cout<<f<<endl;
		rep(i,n+5) dist[i]=1e12,inq[i]=false;
		dist[s]=0;
		q.push(s);inq[s]=true;
    while(!q.empty())
    {
    	//cout<<q.front()<<' '<<dist[q.front()]<<endl;
      LL p=q.front();q.pop();
      inq[p]=false;
      rep(i,g[p].size())
      {
        if(g[p][i].flow>0&&relax(g[p][i].to,dist[p]+g[p][i].cost,p,i)&& !inq[g[p][i].to])
        {
          q.push(g[p][i].to);
          inq[g[p][i].to]=true;
          //if(p==3&&dist[g[p][i].to]<-(LL)1e6) cout<<i<<" 114514\n";
        }
      }
    }
    //cout<<'p';
		LL curf=f,sum=0;
		for(LL pos=t;pos!=s;pos=prevv[pos])
    {
      curf=min(curf,g[prevv[pos]][preve[pos]].flow);
      sum+=g[prevv[pos]][preve[pos]].cost;
      //cout<<pos<<'h'<<' '<<g[prevv[pos]][preve[pos]].cost<<' '<<prevv[pos]<<' '<<preve[pos]<<endl;
    }
		f-=curf;
		ret+=curf*sum;
		for(LL pos=t;pos!=s;pos=prevv[pos])
		{
			g[prevv[pos]][preve[pos]].flow-=curf;
			g[pos][g[prevv[pos]][preve[pos]].rev].flow+=curf;
      step[prevv[pos]][pos]+=curf;
      step[pos][prevv[pos]]-=curf;
		}
	}
	return ret;
}

LL d,m,nn;
bool mark[1100];
string s;

int main()
{
  cin>>d>>m;
  rep(i,m)
  {
    cin>>s;
    LL res=0;
    rep(i,s.size()) if(s[i]=='1') res|=(1<<i);
    mark[res]=true;
  }
  nn=(1<<d);
  rep(i,nn)
  {
    add_edge(i,i+nn,1e9,0);
    if(mark[i])
    {
      add_edge(i,i+nn,1,-1e6);
      add_edge(i+nn,nn+nn,1e9,1);
    }
    rep(j,d)
    {
      if((i&(1<<j))>0) continue;
      LL nxt=i|(1<<j);
      add_edge(i+nn,nxt,1e9,1);
    }
  }
  n=nn+nn;
  LL res=0;
  vector <pair <LL,char> > ans;ans.clear();
  rep(i,m)
  {
    res+=min_cost_flow(0,n,1);
    if(res<(m-1)*((LL)-1e6))
    {
      cout<<res-m*(-1000000LL)-1<<endl;
      LL lft=res-m*(-1000000LL)-1;
      while(lft>0)
      {
        LL pos=0;
        while(pos!=n)
        {
          LL To=0;
          rep(i,g[pos].size()) if(step[pos][g[pos][i].to]>0) To=g[pos][i].to;
          //cout<<pos<<' '<<To<<endl;
          if(To==0) break;
          if(To!=pos+nn&&To!=n)
          {
            LL tmp=(pos-nn)^To;
            ans.pb(mpr(__builtin_ctz(tmp),' '));
            //cout<<pos<<' '<<To<<' '<<ans.back().fi<<endl;
            --lft;
          }
          if(To==n)
          {
            ans.pb(mpr(-1,'R'));
            //cout<<pos<<' '<<To<<' '<<'R'<<endl;
            --lft;
          }
          --step[pos][To];
          pos=To;
        }
      }
      rep(j,ans.size()-1)
      {
        if(ans[j].fi==-1) cout<<ans[j].se<<' ';
        else cout<<ans[j].fi<<' ';
      }
      cout<<endl;
      return 0;
    }
  }
	return 0;
}