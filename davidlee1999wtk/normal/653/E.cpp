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
#define N 300005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char _ch;
inline void getint(int &_x)
{
	_x=0;
	for(_ch=getchar();_ch>'9'||_ch<'0';_ch=getchar());
	for(;_ch<='9'&&_ch>='0';_ch=getchar())
		_x=_x*10+_ch-48;
}
map<int,int> mp[N];
int sz[N],fa[N],ok[N],vis[N],scc[N];
vector<int> G[N],hv[N];
set<int> s;
int main()
{
    int n,m,k,l,a,b,x,v,ans=0,i,j,cnt=0;
    set<int>::iterator it;
    cin>>n>>m>>k;
    for(i=2;i<=n;i++)
        fa[i]=i,s.insert(i),sz[i]=1,hv[i].push_back(i);
    for(i=1;i<=m;i++)
    {
        //scanf("%d%d",&a,&b);
        getint(a);
        getint(b);
        if(a>b) swap(a,b);
        if(a==1) ok[b]=1,cnt++;
        else
        {
            G[a].push_back(b);
            G[b].push_back(a);
            mp[a][b]=1;
            mp[b][a]=1;
        }
    }
    int flag;
    while(s.size()>=2)
    {
        x=*s.begin();
        it=s.begin();
        flag=0;
        for(it++;it!=s.end();it++)
        {
            v=*it;
            //if(!vis[v])
            if(mp[x][v]!=sz[x])
            {
                flag=1;
                fa[v]=x;
                sz[x]++;
                hv[x].push_back(v);
                for(i=0;i<G[v].size();i++)
                    mp[x][G[v][i]]++;
                s.erase(it);
                break;
            }
        }
        if(!flag)
        {
            ans++;
            scc[ans]=x;
            s.erase(s.begin());
        }
    }
    ans++;
    scc[ans]=*s.begin();
    //debug(ans);
    if(ans>k)
    {
        printf("impossible\n");
        return 0;
    }
    if(n-1-cnt<k)
    {
        printf("impossible\n");
        return 0;
    }
    for(l=1;l<=ans;l++)
    {
        i=scc[l];
        flag=0;
        for(j=0;j<hv[i].size();j++)
            if(!ok[hv[i][j]])
                flag=1;
        if(flag==0)
        {
            //debug(ans);
            printf("impossible\n");
            return 0;
        }
    }
    printf("possible\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))