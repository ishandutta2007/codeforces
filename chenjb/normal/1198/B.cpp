#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n;
int a[210000];
struct node 
{
    long long x,p;
}st[810000];
void clear(int t)
{
    long long p=st[t].p;
    st[t].p=0;
    st[2*t].p=max(st[2*t].p,p);
    st[2*t+1].p=max(st[2*t+1].p,p);
    st[2*t].x=max(st[2*t].x,p);
    st[2*t+1].x=max(st[2*t+1].x,p);
}
void insert(int t,int l,int r,long long k,long long p)
{
    if (l==r)
    {
        st[t].p=0;
        st[t].x=p;
        return;
    }
    clear(t);
    int mid=(l+r)/2;
    if (k<=mid)insert(2*t,l,mid,k,p);
    else insert(2*t+1,mid+1,r,k,p);
}
long long get(int t,int l,int r,int k)
{
    if (l==r)return st[t].x;
    clear(t);
    int mid=(l+r)/2;
    if (k<=mid)return get(2*t,l,mid,k);
    else return get(2*t+1,mid+1,r,k);
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%lld",get(1,1,n,i));
        if (i<n)putchar(' ');
    }
    puts("");
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)insert(1,1,n,i,a[i]); 
    //print(); 
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int opt;
        scanf("%d",&opt);
        if (opt==1)
        {
            long long p,x;
            scanf("%lld%lld",&p,&x);
            insert(1,1,n,p,x);
        }
        else 
        if (opt==2)
        { 
            long long p; 
            scanf("%lld",&p); 
            st[1].x=max(st[1].x,p); 
            st[1].p=max(st[1].p,p); 
        }
       // print();
    }
    print();

    return 0;
}