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
#define N 400005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,m,k,dx[5]={1,-1,-1,1},dy[5]={1,1,-1,-1};
LL ans[N];
vector<pii> sen[N][5];

pii get_nxt(int x,int y,int d,int &nxt_d)
{
    int t1,t2,nx,ny,t;
    if(dx[d]>0)
        t1=n-x;
    else t1=x;
    if(dy[d]>0)
        t2=m-y;
    else t2=y;

    t=min(t1,t2);
    nx=x+dx[d]*t;
    ny=y+dy[d]*t;
    if(t1==t2)
        nxt_d=4;

    if(d==0)
        if(t1<t2)
            nxt_d=1;
        else nxt_d=3;
    if(d==1)
        if(t1<t2)
            nxt_d=0;
        else nxt_d=2;
    if(d==2)
        if(t1<t2)
            nxt_d=3;
        else nxt_d=1;
    if(d==3)
        if(t1<t2)
            nxt_d=2;
        else nxt_d=0;
    return MP(nx,ny);
}

int get_num(int x,int y)
{
    if(y==0)
        return x;
    else if(x==n)
        return x+y;
    else if(y==m)
        return n+m+(n-x);
    else return 2*n+m+(m-y);
}

void upd(LL &x,LL y)
{
    if(x==-1) x=y;
}

int main()
{
    int i,j,x,y,d,nxt_d,td,num,cnt=0;
    LL now_t;
    pii t;
    cin>>n>>m>>k;
    memset(ans,-1,sizeof(ans));
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        for(d=0;d<4;d++)
        {
            t=get_nxt(x,y,d,nxt_d);
            td=d^2;
            num=get_num(t.fi,t.se);
            sen[num][td].push_back(MP(abs(x-t.fi),i));
        }
    }
    now_t=0;
    x=0,y=0,d=0;
    for(i=1;i<=(n+m)*4;i++)
    {
        num=get_num(x,y);
        for(j=0;j<sen[num][d].size();j++)
        {
            upd(ans[sen[num][d][j].se],now_t+sen[num][d][j].fi);
            cnt++;
        }
        if(cnt>k*2) break;
        t=get_nxt(x,y,d,nxt_d);
        if(nxt_d==4)
            break;
        now_t+=abs(x-t.fi);
        x=t.fi,y=t.se;
        d=nxt_d;
    }
    for(i=1;i<=k;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/