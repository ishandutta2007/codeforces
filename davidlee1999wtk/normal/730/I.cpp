#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#define fi first
#define se second
#define MP(x,y) make_pair(x,y)
#define N 3005
#define INF 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct People
{
    int fi,se,num;
    bool operator<(const People &t)const//???
    {
        return fi<t.fi;
    }
}p[N];
int val[N],num2[N],num1[N],vis[N];
priority_queue<pii> q1,q2;
int main()
{
    int n,P,S,i,ans=0,sum=0,best_i;
    cin>>n>>P>>S;
    for(i=1;i<=n;i++)
        scanf("%d",&p[i].fi),p[i].num=i;
    for(i=1;i<=n;i++)
        scanf("%d",&p[i].se);
    sort(p+1,p+1+n);
    reverse(p+1,p+1+n);
    for(i=n;i>P;i--)
    {
        q1.push(MP(p[i].se,i));
        if(i<=P+S)
        {
            val[i]=val[i+1]+q1.top().fi;
            num2[i]=q1.top().se;
            q1.pop();
        }
    }
    //debug(val[3]);
    for(i=1;i<=P+S;i++)
    {
        sum+=p[i].fi;
        //debug(sum);
        q2.push(MP(p[i].se-p[i].fi,i));
        if(i>P)
        {
            sum+=q2.top().fi;
            num1[i]=q2.top().se;
            q2.pop();
        }
        if(i>=P)
        {
            if(ans<sum+val[i+1])
            {
                ans=sum+val[i+1];
                best_i=i;
            }
        }
    }
    for(i=P+1;i<=best_i;i++)
        vis[num1[i]]=1;

    cout<<ans<<endl;
    for(i=1;i<=best_i;i++)
        if(!vis[i])
            printf("%d ",p[i].num);
    cout<<endl;
    for(i=P+1;i<=best_i;i++)
        printf("%d ",p[num1[i]].num);
    for(i=best_i+1;i<=P+S;i++)
        printf("%d ",p[num2[i]].num);
    cout<<endl;
    return 0;
}