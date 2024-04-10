#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};



char s[105][105];
int ko[105][105];
int n,m,k;

#define INF (1<<29)
int opt[105][105];
priority_queue<pair<int,pii> > Q;
bool dod[105][105];
pii prev[105][105];

int matrix[50][50];

vector<pii> wie;

void dijkstra(int zrx,int zry)
{
	
	REP(i,1,n)REP(j,1,m) opt[i][j]=INF;
	REP(i,1,n)REP(j,1,m) dod[i][j]=0;
    opt[zrx][zry]=0;
    prev[zrx][zry]=mp(zrx,zry);
    Q.push(mp(0,mp(zrx,zry)));
    while(!Q.empty())
    {
        pii p=(Q.top()).se;
        //DBG(p);
        if (dod[p.fi][p.se]) 
        {
            Q.pop();
            continue;
        }
        opt[p.fi][p.se]=-((Q.top()).fi);
        Q.pop();
        dod[p.fi][p.se]=1;
        if ('a'<=s[p.fi][p.se] && s[p.fi][p.se]<='z' && p!=mp(zrx,zry)) continue;
        FOR(K,4)
        {
			int i1=p.fi+dx[K];
			int i2=p.se+dy[K];
			if (s[i1][i2]=='#') continue;
			//DBG(mp(i1,i2));
            if (!dod[i1][i2] && (opt[i1][i2] >opt[p.fi][p.se]+ko[p.fi][p.se]))
            {
                opt[i1][i2]=opt[p.fi][p.se]+ko[p.fi][p.se];
                prev[i1][i2]=p;
                Q.push(mp(-opt[i1][i2],mp(i1,i2)));
            }
        }
    }
}

map<char,pii> tl;
map<pii,int> tl2;
char dr[20000];
vector<pii> trasa;
vi tr;

int main()
{
    //ios_base::sync_with_stdio(0);
    CZ3(n,m,k);
    
    FOR(i,n)
    {
		scanf("%s",s[i+1]+1);
	}
	FOR(i,n+3)FOR(j,m+3) if (i<1 || i>n || j<1 || j>m) s[i][j]='#';
	REP(i,1,n)REP(j,1,m)
	{
		if (isdigit(s[i][j])) ko[i][j]=s[i][j]-'0';
		else ko[i][j]=1;
		if ('a'<=s[i][j] && s[i][j]<='z')
		{
			tl[s[i][j]]=mp(i,j);
			//wie.pb(mp(i,j));
		}
	}
	int x,y;
	CZ2(x,y);
	trasa.pb(mp(x,y));
	scanf("%s",dr);
	int ndr=strlen(dr);
	FOR(i,ndr) trasa.pb(tl[dr[i]]);
	CZ2(x,y);
	trasa.pb(mp(x,y));
	wie=trasa;
	sort(ALL(wie));un(wie);
	FOR(i,wie.sz) tl2[wie[i]]=i;
	FOR(i,trasa.sz) tr.pb(tl2[trasa[i]]);
	//DBG(wie);
	//DBG(tr);
	FOR(i,wie.sz)
	{
		dijkstra(wie[i].fi,wie[i].se);
		FOR(j,wie.sz) matrix[i][j]=opt[wie[j].fi][wie[j].se];
		//DBG(vi(matrix[i],matrix[i]+wie.sz));
	}
	int sum=k;
	FOR(i,tr.sz-1)
	{
		DBG(sum);
		if (matrix[tr[i]][tr[i+1]]>sum)
		{
			
			pii z=wie[tr[i]];
			if (sum==0)
			{
				cout<<z.fi<<" "<<z.se;
				return 0;
			}
			dijkstra(z.fi,z.se);
			pii u=wie[tr[i+1]];
			while(1)
			{
				
				if (opt[u.fi][u.se]<=sum)
				{
					cout<<u.fi<<" "<<u.se;
					return 0;
				}
				pii pu=prev[u.fi][u.se];
				u=pu;
			}
		}
		else sum-=matrix[tr[i]][tr[i+1]];
	}
	cout<<x<<" "<<y;
	
	
	
    return 0;
}