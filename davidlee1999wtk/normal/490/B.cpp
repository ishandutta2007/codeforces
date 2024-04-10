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
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int nxt[1000005];
int vis[1000005];
int main()
{
    int n,a,b,i,t1,t2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        nxt[a]=b;
        vis[a]=max(vis[a],1);
        vis[b]=2;
    }
    for(i=1;i<=1000000;i++)
        if(vis[i]==1)
            t1=i;
    t2=nxt[0];
    for(i=1;i<=n;i++)
    {
        printf("%d ",t1);
        t1=nxt[t1];
        swap(t1,t2);
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);