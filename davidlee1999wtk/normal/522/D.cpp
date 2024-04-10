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
#define N 500005
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,m,a[N],b[N],z,nx[N],h[N],ql,qr,qk,qw,c[N*4],ans,rel[N];
map<int,int> mp;
vector<int> G[N];
int l[N],r[N];
void upd(int &x,int y)
{
    if((x==-1||x>y)&&y!=-1)
        x=y;
}

void Change(int o,int L,int R)
{
    upd(c[o],qw);
    if(L==R)
        return;
    int mid=(L+R)>>1;
    if(qk<=mid)
        Change(o<<1,L,mid);
    else Change(o<<1|1,mid+1,R);
}

void Query(int o,int L,int R)
{
    if(L>=ql&&R<=qr)
    {
        upd(ans,c[o]);
        return;
    }
    int mid=(L+R)>>1;
    if(ql<=mid)
        Query(o<<1,L,mid);
    if(qr>mid)
        Query(o<<1|1,mid+1,R);
}

int main()
{
    int i,j;
    memset(c,-1,sizeof(c));
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    z=unique(b+1,b+1+n)-(b+1);
    for(i=1;i<=z;i++)
        mp[b[i]]=i;
    for(i=n;i;i--)
    {
        a[i]=mp[a[i]];
        nx[i]=h[a[i]];
        h[a[i]]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        G[l[i]].push_back(i);
    }
    for(i=n;i;i--)
    {
        if(nx[i])
        {
            qk=nx[i];
            qw=nx[i]-i;
            Change(1,1,n);
        }
        for(j=0;j<G[i].size();j++)
        {
            ql=l[G[i][j]];
            qr=r[G[i][j]];
            ans=-1;
            Query(1,1,n);
            rel[G[i][j]]=ans;
        }
    }
    for(i=1;i<=m;i++)
        printf("%d\n",rel[i]);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);