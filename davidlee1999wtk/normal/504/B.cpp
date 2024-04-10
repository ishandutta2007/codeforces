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
int s[200005],a[200005],b[200005],n,c[200005],sum[200005*4];
inline int get(int x)
{
    int sum=0;
    x++;
    for(;x;x-=x&-x)
        sum+=s[x];
    return sum;
}

inline void add(int x)
{
    x++;
    for(;x<=n;x+=x&-x)
        s[x]++;
}

int Get(int o,int L,int R,int k)
{
    if(L==R)
        return L;
    int mid=(L+R)>>1;
    if(mid-L+1-sum[o<<1]>=k)
        return Get(o<<1,L,mid,k);
    else
    {
        k-=mid-L+1-sum[o<<1];
        return Get(o<<1|1,mid+1,R,k);
    }
}
void Insert(int o,int L,int R,int k)
{
    if(L==R)
    {
        sum[o]++;
        return;
    }
    int mid=(L+R)>>1;
    sum[o]++;
    if(k<=mid)
        Insert(o<<1,L,mid,k);
    else Insert(o<<1|1,mid+1,R,k);
}

int main()
{
    int i;
    cin>>n;
    for(i=n;i;i--)
        scanf("%d",&a[i]);
    for(i=n;i;i--)
    {
        add(a[i]);
        a[i]-=get(a[i]-1);
        //debug(a[i]);
    }
    memset(s,0,sizeof(s));
    for(i=n;i;i--)
        scanf("%d",&b[i]);
    for(i=n;i;i--)
    {
        add(b[i]);
        b[i]-=get(b[i]-1);
        //debug(b[i]);
    }
    memset(s,0,sizeof(s));
    for(i=1;i<=n;i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/i;
        c[i]%=i;
        //debug(c[i]);
    }
    for(i=n;i;i--)
    {
        c[i]=Get(1,1,n,c[i]+1)-1;
        printf("%d ",c[i]);
        Insert(1,1,n,c[i]+1);
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);