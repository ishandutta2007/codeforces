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
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int c[N],now,sum,a[N],b[N],ans[N],nxt[N],n;
map<int,int> vis,pre;
vector<pii> Q[N];

void Add(int x,int w)
{
    for(;x<=n;x+=x&-x)
        c[x]^=w;
}

int Get(int x)
{
    int s=0;
    for(;x;x-=x&-x)
        s^=c[x];
    return s;
}

int main()
{
    int i,m,ql,qr,j;
    cin>>n;
    now=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]]++;
        nxt[pre[a[i]]]=i;
        pre[a[i]]=i;
        if(vis[a[i]]>1)
            now^=a[i];
        b[i]=now;
        //debug(b[i]);
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&ql,&qr);
        Q[ql].push_back(MP(qr,i));
    }
    for(i=1;i<=n;i++)
    {
        //debug(sum);
        for(j=0;j<Q[i].size();j++)
            ans[Q[i][j].se]=Get(Q[i][j].fi)^b[Q[i][j].fi];
        ql=nxt[i];
        if(ql)
        {
            sum^=a[i];
            Add(ql,a[i]);
        }
    }
    for(i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++