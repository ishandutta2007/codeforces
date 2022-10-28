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
#define INF 100000000
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int du[100005],yh[100005],fr[100005],to[100005],cou;
int main()
{
    int n,i,ans=0,x,v;
    queue<int> q;
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&du[i],&yh[i]);
        ans+=du[i];
        if(du[i]==1)
            q.push(i);
    }
    ans/=2;
    while(!q.empty())
    {
        x=q.front(),q.pop();
        if(du[x]==1)
        {
            v=yh[x];
            fr[++cou]=x,to[cou]=v;
            du[v]--;
            yh[v]^=x;
            if(du[v]==1) q.push(v);
        }
    }
    cout<<ans<<endl;
    for(i=1;i<=ans;i++)
        printf("%d %d\n",fr[i],to[i]);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
1
0 0
*/