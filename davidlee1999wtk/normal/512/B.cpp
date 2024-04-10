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
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
map<int,int> dp;
int tl[305],tc[305];
map<int,int>::iterator it;
int main()
{
    int n,x,i,l,c;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>tl[i];
    for(i=1;i<=n;i++)
        cin>>tc[i];
    for(i=1;i<=n;i++)
    {
        l=tl[i],c=tc[i];
        for(it=dp.begin();it!=dp.end();it++)
        {
            x=it->fi;
            x=__gcd(x,l);
            if(!dp[x])
                dp[x]=it->se+c;
            else dp[x]=min(dp[x],it->se+c);
        }
        x=l;
        if(!dp[x])
            dp[x]=it->se+c;
        else dp[x]=min(dp[x],it->se+c);
    }
    if(dp[1]==0)
        printf("-1\n");
    else printf("%d\n",dp[1]);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);