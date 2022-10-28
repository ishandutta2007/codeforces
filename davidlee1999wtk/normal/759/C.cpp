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
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp[N*4],sum[N*4],qk,qw,qv,val[N*4],ans,now;
void Push_up(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
    dp[o]=max(dp[o<<1|1],dp[o<<1]+sum[o<<1|1]);
}

void Change(int o,int L,int R)
{
    if(L==R)
    {
        dp[o]=sum[o]=qw;
        val[o]=qv;
        return;
    }
    int mid=(L+R)>>1;
    if(qk<=mid)
        Change(o<<1,L,mid);
    else Change(o<<1|1,mid+1,R);
    Push_up(o);
}

void Query(int o,int L,int R)
{
    if(L==R)
    {
        ans=val[o];
        return;
    }
    int mid=(L+R)>>1;
    if(dp[o<<1|1]+now>0)
        Query(o<<1|1,mid+1,R);
    else
    {
        now+=sum[o<<1|1];
        Query(o<<1,L,mid);
    }
}

int main()
{
    int n,i,op;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&qk,&op);
        if(op==0)
        {
            qw=-1;
            qv=0;
            Change(1,1,n);
        }
        else
        {
            qw=1;
            scanf("%d",&qv);
            Change(1,1,n);
        }
        if(dp[1]<=0)
            printf("-1\n");
        else
        {
            now=0;
            Query(1,1,n);
            printf("%d\n",ans);
        }
    }
    /*
    set<pii> s;
    //debug((s.begin()==s.end()));
    set<pii>::iterator it;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&p,&op);
        if(op==0)
        {
            it=s.upper_bound(MP(p,0));
            if(it==s.begin())
                s.insert(MP(p,0));
            else
            {
                it--;
                if((*it).se==0)
                    s.insert(MP(p,0));
                else
                    s.erase(it);
            }
        }
        else
        {
            scanf("%d",&x);
            it=s.upper_bound(MP(p,x));
            if(it==s.end())
                s.insert(MP(p,x));
            else
            {
                if((*it).se==0)
                    s.erase(it);
                else
                    s.insert(MP(p,x));
            }
        }
        it=s.end();
        if(s.empty())
            printf("-1\n");
        else
        {
            it--;
            if((*it).se==0)
                printf("-1\n");
            else printf("%d\n",(*it).se);
        }
    }*/
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
5
1 1 2
3 1 3
2 0
4 0
5 1 4
*/