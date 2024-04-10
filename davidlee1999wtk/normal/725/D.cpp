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
#define N 300005
#define P 1000000007
#define K 61
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
pll t[N];
LL inf=1000000000ll*1000000000ll+1,sum;

priority_queue<LL> q1;

priority_queue<LL,vector<LL>,greater<LL> > q2;

int main()
{
    int n,i,ans=INF,m;
    LL use=0,t1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%I64d",&t[i].fi,&t[i].se);
        t[i].se-=t[i].fi;
        t[i].se++;
    }
    t1=t[1].fi;
    sort(t+2,t+1+n);
    for(i=1;i<=n;i++)
    {
        //debug(t[i].fi);
        //debug(t[i].se);
        ;
    }
    for(i=n;i;i--)
    {
        if(t[i].fi<=t1)
            break;
    }
    //debug(n-i+1);
    if(i==n)
    {
        printf("1\n");
        return 0;
    }
    t[1].fi=0;
    use=t1-t[i].fi;
    m=i;
    sum=0;
    for(i=n;i>m;i--)
    {
        //debug(use);
        if(q1.empty()||t[i].se>=q1.top())
            q2.push(t[i].se);
        else
        {
            if(sum+t[i].se>use)
            {
                if(!q1.empty())
                {
                    if(q1.top()>t[i].se)
                    {
                        q2.push(q1.top());
                        sum-=q1.top();
                        q1.pop();
                        q1.push(t[i].se);
                        sum+=t[i].se;
                    }
                }
                else q2.push(t[i].se);
            }
            else
            {
                q1.push(t[i].se);
                sum+=t[i].se;
            }
        }
        while(!q2.empty()&&q2.top()+sum<=use)
        {

            sum+=q2.top();
            q1.push(q2.top());
            q2.pop();
        }
        //debug(sum);
        //debug(q1.size());
    }
    //return 0;
    //debug(1235566);
    ans=min(ans,n-m+1-(int)q1.size());
    for(i=m;i>1;i--)
    {
        use=t1-t[i-1].fi;
        //debug(i-1);
        //debug(t[i-1].fi);
        //debug(use);
        //debug(t[i].se);
        if(q1.empty()||t[i].se>=q1.top())
            q2.push(t[i].se);
        else
        {
            if(sum+t[i].se>use)
            {
                if(!q1.empty())
                {
                    if(q1.top()>t[i].se)
                    {
                        q2.push(q1.top());
                        sum-=q1.top();
                        q1.pop();
                        q1.push(t[i].se);
                        sum+=t[i].se;
                    }
                }
                else q2.push(t[i].se);
            }
            else
            {
                q1.push(t[i].se);
                sum+=t[i].se;
            }
        }
        while(!q2.empty()&&q2.top()+sum<=use)
        {

            sum+=q2.top();
            q1.push(q2.top());
            q2.pop();
        }
        //debug(q1.size());
        //debug(sum);
        ans=min(ans,n-i+1+1-(int)q1.size());
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
9
2
14
5
7
*/