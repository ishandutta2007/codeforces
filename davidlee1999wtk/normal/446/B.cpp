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
priority_queue<LL> r,c;
LL sr[1005],sc[1005],tr,tc;
LL nr[1000005],nc[1000005],sumr[1000005],sumc[1000005];
int main()
{
    LL n,m,k,p,i,j;
    LL ans=-1000000000000000;
    int a;
    cin>>n>>m>>k>>p;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a);
            sr[i]+=a;
            sc[j]+=a;
        }
    for(i=1;i<=n;i++)
        r.push(sr[i]);
    for(i=1;i<=m;i++)
        c.push(sc[i]);
    for(i=1;i<=k;i++)
    {
        tr=r.top();
        nr[i]=tr;
        r.pop();
        r.push(tr-p*m);
        sumr[i]=sumr[i-1]+nr[i];
    }
    for(i=1;i<=k;i++)
    {
        tc=c.top();
        nc[i]=tc;
        c.pop();
        c.push(tc-p*n);
        sumc[i]=sumc[i-1]+nc[i];
    }
    //cout<<sumr[2]<<endl;
    //cout<<sumr[2]+sumc[3]<<endl;
    for(i=0;i<=k;i++)
        ans=max(sumr[i]+sumc[k-i]-i*(k-i)*p,ans);
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
2 2 2 2
1 1
1 1
*/