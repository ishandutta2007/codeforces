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
#define N 400005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,k;
int sa[2][N],rk[2][N*2],v[N],h[N],*Sa,*Rk,he[N],st[N][19],lg[N];
char s[N],p[N];
void calc(int *SA,int *sa,int *RK,int *rk)
{
    int i;
    for(i=1;i<=n;i++)
        v[rk[sa[i]]]=i;
    for(i=n;i;i--)
        if(sa[i]>k)
            SA[v[rk[sa[i]-k]]--]=sa[i]-k;
    for(i=n-k+1;i<=n;i++)
        SA[v[rk[i]]--]=i;
    for(i=1;i<=n;i++)
        RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
}

void get_H()
{
    int i,j,k=0;
    for(i=1;i<=n;i++)
    {
        if(k) k--;
        j=Sa[Rk[i]-1];
        while(s[i+k]==s[j+k])
            k++;
        he[Rk[i]]=k;
        st[Rk[i]][0]=k;
    }
}

void initlog()
{
    int i,j=2;
    lg[1]=0;
    for(i=2;i<=n;i++)
    {
        if(i==j)
        {
            lg[i]=lg[i-1]+1;
            j=j<<1;
        }
        else lg[i]=lg[i-1];
    }
}

void get_ST()
{
    int i,j,m=lg[n];
    for(j=1;j<=m;j++)
        for(i=1;i<=n-(1<<j)+1;i++)
        {
            //debug(i);
            //debug(j);
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
            //debug(st[i][j]);
        }
}

inline int rmp(int ql,int qr)
{
    if(ql==qr)
        return n-ql+1;
    ql++;
    int m=lg[qr-ql+1];
    //debug(ql);
    //debug(qr);
    //debug(min(st[ql][m],st[qr-(1<<m)+1][m]));
    return min(st[ql][m],st[qr-(1<<m)+1][m]);
}

int sum[N*19],lch[N*19],rch[N*19],rt[N],qk,ql,qr,tot,ans;
void Insert(int &x,int y,int L,int R)
{
    x=++tot;
    sum[x]=sum[y]+1;
    if(L==R)
        return;
    int mid=(L+R)>>1;
    if(qk<=mid)
    {
        rch[x]=rch[y];
        Insert(lch[x],lch[y],L,mid);
    }
    else
    {
        lch[x]=lch[y];
        Insert(rch[x],rch[y],mid+1,R);
    }
}

void Get(int x,int y,int L,int R)
{
    if(ql<=L&&R<=qr)
    {
        ans+=sum[y]-sum[x];
        return;
    }
    int mid=(L+R)>>1;
    if(ql<=mid)
        Get(lch[x],lch[y],L,mid);
    if(qr>mid)
        Get(rch[x],rch[y],mid+1,R);
}

int main()
{
    int m,qu,now=0,i,p=0,q=1,L,R;
    int l,r,mid,len;
    cin>>m>>qu;
    for(i=1;i<=m;i++)
    {
        now++;
        h[i]=now;
        scanf("%s",s+now);
        now+=strlen(s+now);
        s[now]='#';
    }
    h[m+1]=now+1;
    n=now;
    initlog();
    for(i=1;i<=n;i++)
        v[s[i]]++;
    for(i=1;i<=300;i++)
        v[i]+=v[i-1];
    Sa=sa[p];
    Rk=rk[p];
    for(i=1;i<=n;i++)
        Sa[v[s[i]]--]=i;
    for(i=1;i<=n;i++)
        Rk[Sa[i]]=Rk[Sa[i-1]]+(s[Sa[i]]!=s[Sa[i-1]]);
    k=1;
    while(k<n)
    {
        swap(p,q);
        calc(sa[p],sa[q],rk[p],rk[q]);
        k<<=1;
    }
    Sa=sa[p];
    Rk=rk[p];
    //for(i=1;i<=n;i++)
        //debug(Sa[i]),debug(Rk[i]);
    get_H();
    get_ST();
    //for(i=1;i<=n;i++)
        //debug(he[i]);
    for(i=1,p=0;i<=n;i++)
    {
        if(i==h[p+1])
            p++,rt[p]=rt[p-1];
        if(s[i]!='#')
        {
            qk=Rk[i];
            Insert(rt[p],rt[p],1,n);
        }
    }
    while(qu--)
    {
        scanf("%d%d%d",&L,&R,&i);
        len=h[i+1]-h[i]-1;
        //debug(len);
        i=Rk[h[i]];
        //debug(i);
        l=1,r=i;
        while(l<r)
        {
            //debug(l);
            mid=(l+r)>>1;
            if(rmp(mid,i)>=len)
                r=mid;
            else l=mid+1;
        }
        ql=l;
        l=i,r=n;
        while(l<r)
        {
            //debug(l);
            //debug(r);
            mid=(l+r+1)>>1;
            if(rmp(i,mid)>=len)
                l=mid;
            else r=mid-1;
        }
        qr=r;
        //debug(ql);
        //debug(qr);
        ans=0;
        Get(rt[L-1],rt[R],1,n);
        printf("%d\n",ans);
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
/*
3 1
aa
aaa
a
1 2 1
*/