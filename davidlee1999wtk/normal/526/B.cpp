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
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int w[2500];
int now[2500],f[2500];
void dp(int x,int L,int R)
{
    if(L==R)
    {
        now[x]=w[x];
        f[x]=0;
        return;
    }
    int mid=(L+R)>>1;
    dp(x<<1,L,mid);
    dp(x<<1|1,mid+1,R);
    now[x]=max(now[x<<1],now[x<<1|1]);
    f[x]=f[x<<1]+f[x<<1|1]+now[x]*2-now[x<<1]-now[x<<1|1];
    now[x]+=w[x];
}

int main()
{
    int n,i,cf;
    cin>>n;
    cf=(1<<n+1)-1;
    for(i=2;i<=cf;i++)
        scanf("%d",&w[i]);
    dp(1,1,(1<<n));
    cout<<f[1]<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);