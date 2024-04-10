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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int c[3005];
vector<int> t1[3005],t2[3005];
int main()
{
    int i,n,v,sum=0,ans=0,day,j,m,x;
    cin>>n>>v;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&day,&c[i]);
        t1[day].push_back(i);
        t2[day+1].push_back(i);
    }
    //sort(c+1,c+1+n);
    for(i=1;i<=3001;i++)
    {
        sum=v;
        m=t2[i].size();
        for(j=0;j<m;j++)
        {
            x=t2[i][j];
            if(sum>=c[x])
                sum-=c[x];
            else
            {
                sum=0;
                break;
            }
        }
        if(j!=m)
        {
            ans+=v;
            continue;
        }
        m=t1[i].size();
        for(j=0;j<m;j++)
        {
            x=t1[i][j];
            if(sum>=c[x])
                sum-=c[x],c[x]=0;
            else
            {
                c[x]-=sum;
                sum=0;
                break;
            }
        }
        ans+=v-sum;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);