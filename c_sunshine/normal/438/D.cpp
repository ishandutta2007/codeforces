#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
inline void readi(int &x);
const int maxn=100005;
int n,Q;
int a[maxn];

struct node
{
    int Max;
    long long Sum;
    node *lc,*rc;
    void update()
    {
        Max=max(lc->Max,rc->Max);
        Sum=lc->Sum+rc->Sum;
    }
    void Modulo(int l,int r,const int &a,const int &b,const int &m)
    {
        if(Max<m)return;
        if(l==r)
            Max=Sum=Sum%m;
        else
        {
            int mid=l+r>>1;
            if(a<=mid)lc->Modulo(l,mid,a,b,m);
            if(b>mid)rc->Modulo(mid+1,r,a,b,m);
            update();
        }
    }
    void Modify(int l,int r,const int &k,const int &x)
    {
        if(l==r)
            Max=Sum=x;
        else
        {
            int mid=l+r>>1;
            if(k<=mid)lc->Modify(l,mid,k,x);
            else rc->Modify(mid+1,r,k,x);
            update();
        }
    }
    long long Query(int l,int r,const int &a,const int &b)
    {
        if(l>=a&&r<=b)return Sum;
        int mid=l+r>>1;
        long long ret=0;
        if(a<=mid)ret+=lc->Query(l,mid,a,b);
        if(b>mid)ret+=rc->Query(mid+1,r,a,b);
        return ret;
    }
}ndl[maxn*2],*root;
int ns=1;

node* build(int l,int r)
{
    node *c=ndl+ns++;
    if(l==r)
        c->Sum=c->Max=a[l];
    else
    {
        int mid=l+r>>1;
        c->lc=build(l,mid);
        c->rc=build(mid+1,r);
        c->update();
    }
    return c;
}

void init()
{
    readi(n),readi(Q);
    for(int i=1;i<=n;i++)readi(a[i]);
    root=build(1,n);
}

void work()
{
    for(int opt,l,r,k,x;Q--;)
    {
        readi(opt);
        if(opt==1)
        {
            readi(l),readi(r);
            printf("%I64d\n",root->Query(1,n,l,r));
        }
        else if(opt==2)
        {
            readi(l),readi(r),readi(x);
            root->Modulo(1,n,l,r,x);
        }
        else
        {
            readi(k),readi(x);
            root->Modify(1,n,k,x);
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
inline void readi(int &x)
{
  char c;for(c=getchar();c>'9'||c<'0';c=getchar());
  x=c^'0';for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+(c^'0');
}