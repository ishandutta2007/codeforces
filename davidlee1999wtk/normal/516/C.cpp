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
#define N 100005
#define debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL c1[N*4],c2[N*4],c3[N*4],v1[N*4],v2[N*4],v3[N*4],d[N],sd[N],ql,qr,r1,r2,r3;
LL d1[N*4],d2[N*4],d3[N*4],l1[N*4],l2[N*4],l3[N*4],q1,q2,w1,w2;
LL inf=(LL(10000000)*1000000000);
void build_tree(int o,int L,int R)
{
    if(L==R)
    {
        c1[o]=v1[L];
        c2[o]=v2[L];
        c3[o]=v3[L];
        l1[o]=l2[o]=l3[o]=L;
        d1[o]=-inf;
        d2[o]=-inf;
        d3[o]=-inf;
        return;
    }
    int mid=(L+R)>>1;
    build_tree(o<<1,L,mid);
    build_tree(o<<1|1,mid+1,R);
    c1[o]=max(c1[o<<1],c1[o<<1|1]);
    d1[o]=max(max(d1[o<<1],d1[o<<1|1]),min(c1[o<<1],c1[o<<1|1]));
    if(c1[o<<1]>c1[o<<1|1])
        l1[o]=l1[o<<1];
    else l1[o]=l1[o<<1|1];

    c2[o]=max(c2[o<<1],c2[o<<1|1]);
    d2[o]=max(max(d2[o<<1],d2[o<<1|1]),min(c2[o<<1],c2[o<<1|1]));
    if(c2[o<<1]>c2[o<<1|1])
        l2[o]=l2[o<<1];
    else l2[o]=l2[o<<1|1];

    c3[o]=max(c3[o<<1],c3[o<<1|1]);
    //d3[o]=max(max(d3[o<<1],d3[o<<1|1]),min(c3[o<<1],c3[o<<1|1]));
}

void Query(int o,int L,int R)
{
    if(ql<=L&&qr>=R)
    {
        //debug(o);
        //debug(c3[o]);
        /*
        r1=max(r1,c1[o]);
        r2=max(r2,c2[o]);*/
        r3=max(r3,c3[o]);
        if(c1[o]>r1)
            q1=max(r1,d1[o]),r1=c1[o],w1=l1[o];
        else q1=max(q1,c1[o]);

        if(c2[o]>r2)
            q2=max(r2,d2[o]),r2=c2[o],w2=l2[o];
        else q2=max(q2,c2[o]);

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
    int n,m,a,b,i;
    LL ans,t1,t2;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%I64d",&d[i]),sd[i]=sd[i-1]+d[i];
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&v1[i]),v3[i]=v2[i]=v1[i]=v1[i]*2;
        v1[i]=v1[i]-sd[i-1];
        v2[i]=v2[i]+sd[i-1];
        v3[i]=v3[i]+sd[n]-sd[i-1];
        //debug(v1[i]);
        //debug(v2[i]);
        //debug(v3[i]);
    }
    build_tree(1,1,n);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            ql=b+1,qr=a-1;
            r1=-(LL(10000000)*1000000000);
            q1=q2=r2=r1;
            Query(1,1,n);
            if(w1==w2)
                printf("%I64d\n",max(r1+q2,r2+q1));
            else
                printf("%I64d\n",r1+r2);
            //cout<<r1+r2<<endl;
        }
        else
        {
            ql=1,qr=a-1;
            ans=t1=t2=-(LL(10000000)*1000000000);
            if(ql<=qr)
            {
                r1=-(LL(10000000)*1000000000);
                q1=q2=r2=r1;
                Query(1,1,n);
                t1=r2;
                if(qr>ql)
                {
                    if(w1==w2)
                        ans=max(ans,max(r1+q2,r2+q1));
                    else ans=max(ans,r1+r2);
                }
            }
            ql=b+1,qr=n;
            if(ql<=qr)
            {
                r1=-(LL(10000000)*1000000000);
                q1=q2=r3=r2=r1;
                Query(1,1,n);
                //debug(r1);
                //debug(r2);
                //debug(r3);
                //debug(w1),debug(w2);
                t2=r3;
                if(qr>ql)
                {
                    if(w1==w2)
                        ans=max(ans,max(r1+q2,r2+q1));
                    else ans=max(ans,r1+r2);
                }
            }
            ans=max(ans,t1+t2);
            printf("%I64d\n",ans);
            //cout<<ans<<endl;
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
5 3
2 2 2 2 2
3 5 2 1 4
1 3
2 2
4 5
*/