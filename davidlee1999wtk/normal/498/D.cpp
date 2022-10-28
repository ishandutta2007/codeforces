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
#define N 100005
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n;
int c[N*4][63],a[N],qk,qw,ql,qr,ans;
void push_up(int o)
{
    for(int i=0;i<60;i++)
    {
        int x=c[o<<1][i]+1;
        c[o][i]=x+c[o<<1|1][(x+i)%60];
    }
}

void build_tree(int o,int L,int R)
{
    int i;
    if(L==R)
    {
        for(i=0;i<60;i++)
            if(i%a[L]==0)
                c[o][i]=1;
            else c[o][i]=0;
        return;
    }
    int mid=(L+R)>>1;
    build_tree(o<<1,L,mid);
    build_tree(o<<1|1,mid+1,R);
    push_up(o);
}

void Change(int o,int L,int R)
{
    if(L==R)
    {
        for(int i=0;i<60;i++)
            if(i%a[L]==0)
                c[o][i]=1;
            else c[o][i]=0;
        return;
    }
    int mid=(L+R)>>1;
    if(qk<=mid)
        Change(o<<1,L,mid);
    else Change(o<<1|1,mid+1,R);
    push_up(o);
}

void Query(int o,int L,int R)
{
    if(L>=ql&&R<=qr)
    {
        ans=ans+c[o][ans%60]+1;
        return;
    }
    int mid=(L+R)>>1;
    if(ql<=mid)
        Query(o<<1,L,mid);
    if(qr>mid)
        Query(o<<1|1,mid+1,R);
}

char op[2];
int main()
{
    int i,m;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build_tree(1,1,n);
    cin>>m;
    while(m--)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            scanf("%d%d",&qk,&qw);
            a[qk]=qw;
            Change(1,1,n);
        }
        else
        {
            scanf("%d%d",&ql,&qr);
            qr--;
            ans=0;
            Query(1,1,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
10
2 5 4 2 3 5 3 4 2 6
10
A 3 11


C 10 6
A 2 6
A 1 3
C 3 4
A 3 11
A 4 9
A 5 6
C 7 3
A 8 10
A 2 5
*/