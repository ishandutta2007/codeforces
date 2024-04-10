#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
int n,c,m;
int p[300009],ps[300009];
struct node
{
	ll rk;
	int bg,id;
	bool operator<(const node &p)const{return rk<p.rk;}
};
struct seg
{
	ll rep;
	int l,r,c;
};
vector<node> q[5];
vector<pii> out[300009];
int err[300009];
ll cl[300009][5];
ll lf[300009],rf[300009];
ll cb(int a,int b)
{
	if(a<0||b>a||b<0)
		return 0;
	b=min(b,a-b);
	ll ans=1;
	for(int i=1;i<=b;i++)
		ans*=(a-i+1);
	for(int i=1;i<=b;i++)
		ans/=i;
	return ans;
}
ll cal(int n,int c)
{
	if(n==0)
		return 1;
	ll ans=0;
	for(int i=0;i<=c;i++)
		ans+=cb(n-1,i);
	return ans;
}
void init()
{
	for(int i=0;i<=300000;i++)
		for(int j=0;j<=4;j++)
			cl[i][j]=cal(i,j);
}
void solve()
{
	deque<seg> dq;//remaining leng,remaining c
	for(int i=c;i>=1;i--)
	{
		dq.clear();
		dq.push_back(seg{1,1,0,i});
		lf[n+1]=rf[n+1]=0;
		for(int j=n;j>=1;j--)
		{
			vector<pii> tmp;
			vector<seg> tft;
			lf[j]=lf[j+1];
			rf[j]=rf[j+1];
			for(int k=j;k<=min(n,j+i);k++)
				tmp.push_back(pii(p[k],k));
			int fg=0;
			sort(tmp.begin(),tmp.end());
			for(pii t:tmp)
			{
				if(t.se==j)
					fg=1;
				else if(!fg)
				{
					tft.push_back(seg{cl[n-t.se][i-(t.se-j)],j,t.se,i-(t.se-j)});
					lf[j]-=cl[n-t.se][i-(t.se-j)];
				}
				else
				{
					dq.push_back(seg{cl[n-t.se][i-(t.se-j)],j,t.se,i-(t.se-j)});
					rf[j]+=cl[n-t.se][i-(t.se-j)];
				}
			}
			for(auto it=tft.rbegin();it!=tft.rend();it++)
				dq.push_front(*it);
		}
		// for(seg t:dq)
		// 	printf("rep:%lld l:%d r:%d c:%d\n",t.rep,t.l,t.r,t.c);
		for(auto it=q[i].begin();it!=q[i].end();it++)
		{
			it->rk+=(lf[it->bg]-lf[1]);
			it->bg=1;
		}
		sort(q[i].begin(),q[i].end());
		ll sm=0,lsm=0;
		int lp=-1;
		for(node t:q[i])
		{
			while(lp+1<dq.size()&&sm<t.rk)
			{
				lsm=sm,sm+=dq[++lp].rep;
				// printf("lp:%d sm:%lld\n",lp,sm);
			}
			seg s=dq[lp];
			out[t.id].push_back(pii(s.l,s.r));
			q[s.c].push_back(node{t.rk-lsm,s.r+1,t.id});
		}
	}
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&c,&m);
		for(int i=0;i<=c;i++)
			q[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",p+i);
		ll tot=cl[n][c];
		// printf("tot:%d\n",tot);
		for(int i=1;i<=m;i++)
		{
			err[i]=0;
			out[i].clear();
			int a;
			ll b;
			scanf("%d%lld",&a,&b);
			if(b<=tot)
				q[c].push_back(node{b,1,i});
			else
				err[i]=1;
			ps[i]=a;
		}
		solve();
		for(int i=1;i<=m;i++)
			if(err[i])
				printf("-1\n");
			else
			{
				int s=ps[i];
				// printf("s:%d\n",s);
				for(pii t:out[i])
					if(t.fi<=s&&s<=t.se)
						s=t.fi+t.se-s;
				printf("%d\n",p[s]);
			}
	}
	return 0;
}