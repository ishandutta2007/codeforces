#include <iostream>
#include <cstdio>
#include <cmath>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
using namespace std;
int st[3000010],a[500010],opt,n,q;
int gcd(int x,int y)
{
    if (y==0)return x;
    return gcd(y,x%y);
}
void build(int t,int l,int r)
{
    if(l==r)
    {
        st[t]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(t*2,l,mid);
    build(t*2+1,mid+1,r);
    st[t]=gcd(st[t*2],st[t*2+1]);
}
void insert(int p,int ll,int rr,int x,int y)
{
    if(ll==rr)
    {
        st[p]=y;
        return;
    }
    int mid=(ll+rr)/2;
    if(x<=mid)insert(p*2,ll,mid,x,y);
    else insert(p*2+1,mid+1,rr,x,y);
    st[p]=gcd(st[p*2],st[p*2+1]);
}
int get(int way,int p,int ll,int rr,int r,int x)
{
    int mid=(ll+rr)/2;
    if (way==1)
    {
        if(rr<=r)
        {
            if(ll==rr)
            {
                if (st[p]%x==0)return rr; else return rr+1;  
            }
            if(st[p*2+1]%x==0)return get(1,p*2,ll,mid,r,x);
            else return get(1,p*2+1,mid+1,rr,r,x);
        }
        if(r<=mid)return get(1,p*2,ll,mid,r,x);
        else
        {
            int tmp=get(1,p*2+1,mid+1,rr,r,x);
            if(tmp==mid+1)return get(1,p*2,ll,mid,r,x);
            else return tmp;
        }
    }
    else
    {
        if(ll>=r)
        {
            if(ll==rr)
            {
                if (st[p]%x==0)return ll; else return ll-1;
            }
            if(st[p*2]%x==0)return get(2,p*2+1,mid+1,rr,r,x);
            else return get(2,p*2,ll,mid,r,x);
        }
        if(r>mid)return get(2,p*2+1,mid+1,rr,r,x);
        else
        {
            int tmp=get(2,p*2,ll,mid,r,x);
            if(tmp==mid)return get(2,p*2+1,mid+1,rr,r,x);
            else return tmp;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);

    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int way,l,r,x,y;
        scanf("%d",&way);
        if(way==1)
        {
            scanf("%d%d%d",&l,&r,&x);
            int t1=get(2,1,1,n,l,x);
            int t2=get(1,1,1,n,r,x);
            if (t2-t1<=2)puts("YES"); else puts("NO");
        }
        else
        {
            scanf("%d%d",&x,&y);
            insert(1,1,n,x,y);
        }
    }
    return 0;
}