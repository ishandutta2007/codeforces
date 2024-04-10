#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Line
{
	int r1,r2,c1,c2;
	int op; //op = 0 is horizental
}l[N];
map<int,int> mpx,mpy;
int fmx[N],fmy[N],bx[N],by[N],pro[N],R,C;
vector<pii> h[N],v[N],hor[N],ver[N];
pii p[N];
vector<int> out;
inline bool cmp(pii a,pii b)
{
	if(a.fi==b.fi) return a.se>b.se;
	return a.fi<b.fi;
}
int c[N];
inline void upd(int x,int w)
{
	for(;x<=C;x+=(x&-x))
		c[x]+=w;
}

inline int get(int x)
{
	int sum=0;
	for(;x;x-=(x&-x))
		sum+=c[x];
	return sum;
}

int main()
{
	int n,m,i,j,now,fr,ed,num; //n1 is horizontal
	priority_queue<pii,vector<pii>,greater<pii> > q;
	LL ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&l[i].r1,&l[i].c1,&l[i].r2,&l[i].c2);
		bx[i*2-1]=l[i].r1;
		bx[i*2]=l[i].r2;
		by[i*2-1]=l[i].c1;
		by[i*2]=l[i].c2;
		if(l[i].r1==l[i].r2)
			l[i].op=1;
		else l[i].op=0;
	}
	sort(bx+1,bx+1+n*2);
	sort(by+1,by+1+n*2);
	R=unique(bx+1,bx+1+n*2)-(bx+1);
	C=unique(by+1,by+1+n*2)-(by+1);
	for(i=1;i<=R;i++)
	{
		mpx[bx[i]]=i;
		fmx[i]=bx[i];
	}
	for(i=1;i<=C;i++)
	{
		mpy[by[i]]=i;
		fmy[i]=by[i];
	}
	for(i=1;i<=n;i++)
	{
		l[i].r1=mpx[l[i].r1];
		l[i].r2=mpx[l[i].r2];
		l[i].c1=mpy[l[i].c1];
		l[i].c2=mpy[l[i].c2];
		if(l[i].op==0)
		{
			if(l[i].r1>l[i].r2) swap(l[i].r1,l[i].r2);
			hor[l[i].c1].push_back(MP(l[i].r1,l[i].r2));
		}
		else
		{
			if(l[i].c1>l[i].c2) swap(l[i].c1,l[i].c2);
			ver[l[i].r1].push_back(MP(l[i].c1,l[i].c2));
		}
	}
	//debug(R);
	//debug(C);
	for(i=1;i<=C;i++)
	{
		m=hor[i].size();
		if(m)
		{
			for(j=0;j<m;j++)
			{
				p[j*2+1].fi=hor[i][j].fi;
				p[j*2+1].se=1;
				p[j*2+2].fi=hor[i][j].se;
				p[j*2+2].se=-1;
			}
			sort(p+1,p+1+m*2,cmp);
			now=0;
			for(j=1;j<=m*2;j++)
			{
				now+=p[j].se;
				if(p[j].se==1&&now==1)
					fr=p[j].fi;
				else if(p[j].se==-1&&now==0)
				{
					ed=p[j].fi;
					h[i].push_back(MP(fr,ed));
					ans+=fmx[ed]-fmx[fr]+1;
				}
			}
		}
	}
	//debug(ans);
	for(i=1;i<=R;i++)
	{
		m=ver[i].size();
		if(m)
		{
			for(j=0;j<m;j++)
			{
				p[j*2+1].fi=ver[i][j].fi;
				p[j*2+1].se=1;
				p[j*2+2].fi=ver[i][j].se;
				p[j*2+2].se=-1;
			}
			sort(p+1,p+1+m*2,cmp);
			now=0;
			for(j=1;j<=m*2;j++)
			{
				now+=p[j].se;
				if(p[j].se==1&&now==1)
					fr=p[j].fi;
				else if(p[j].se==-1&&now==0)
				{
					ed=p[j].fi;
					v[i].push_back(MP(fr,ed));
					ans+=fmy[ed]-fmy[fr]+1;
				}
			}
		}
	}
	//debug(ans);
	for(i=1;i<=C;i++)
		if(h[i].size())
		{
			q.push(MP(h[i][0].fi,i));
			pro[i]=0;
		}
	for(i=1;i<=R;i++) //first add,second count,last minus
	{
		out.clear();
		while(!q.empty()&&q.top().fi==i)
		{
			num=q.top().se;
			q.pop();
			if(pro[num]%2==0)
			{
				pro[num]++;
				upd(num,1);
				//debug(num);
				q.push(MP(h[num][pro[num]/2].se,num));
			}
			else
			{
				pro[num]++;
				//debug(num);
				out.push_back(num);
				if(pro[num]/2<h[num].size())
                    q.push(MP(h[num][pro[num]/2].fi,num));
			}
		}
		for(j=0;j<v[i].size();j++)
        {
            //debug(v[i][j].fi);
            //debug(v[i][j].se);
            //debug(get(v[i][j].se));
            //debug(get(v[i][j].fi-1));
			ans-=get(v[i][j].se)-get(v[i][j].fi-1);
        }
		for(j=0;j<out.size();j++)
			upd(out[j],-1);
	}
	//return 0;
	cout<<ans<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))