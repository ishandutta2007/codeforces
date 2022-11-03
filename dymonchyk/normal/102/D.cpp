#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <ctime>
#pragma comment(linker,"/STACK:64000000")

#define ll long long

using namespace std;

struct item{
    item(int _l = 0,int _r = 0) : l(_l), r(_r) {};
    int l,r;
};

bool operator < (const item & a,const item & b)
{
    return a.r<b.r||a.r==b.r&&a.l<b.l;
}

item bus[100001];
vector <int> v;

int mod=1000000007;
int tree[1000000];

int find(int i,int l,int r,int L,int R)
{
    if (l==L&&r==R) return tree[i];
    int m=(l+r)>>1;
    if (R<=m) return find(2*i,l,m,L,R);
    if (L>m) return find(2*i+1,m+1,r,L,R);
    int res=find(2*i,l,m,L,m)+find(2*i+1,m+1,r,m+1,R);
    if (res>=mod) res-=mod;
    return res;
}

void update(int i,int l,int r,int pos,int val)
{
    if (l==r)
    {
        tree[i]=val;
        return;
    }
    int m=(l+r)>>1;
    if (pos<=m) update(2*i,l,m,pos,val);
    else update(2*i+1,m+1,r,pos,val);
    tree[i]=tree[2*i]+tree[2*i+1];
    if (tree[i]>=mod) tree[i]-=mod;
}

map <int,int> f;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&bus[i].l,&bus[i].r);
        v.push_back(bus[i].l);
        v.push_back(bus[i].r);
    }
    v.push_back(0);
    v.push_back(n);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<v.size();i++)
        f[v[i]]=i;
    sort(bus,bus+m);
    int N=v.size();
    update(1,0,N-1,0,1);
    int it=0;
    for(int i=1;i<N;i++)
    {
        int val=0;
        while(it<m&&bus[it].r==v[i])
        {
            val+=find(1,0,N-1,f[bus[it].l],i-1);
            if (val>=mod) val-=mod;
            it++;
        }
        update(1,0,N-1,i,val);
    }
    printf("%d\n",find(1,0,N-1,N-1,N-1));
    return 0;
}