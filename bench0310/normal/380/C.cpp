#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
char s[N];
array<int,3> tree[4*N];
vector<int> v;

array<int,3> upd(array<int,3> a,array<int,3> b)
{
    array<int,3> x;
    int t=min(a[1],b[2]);
    x[0]=a[0]+b[0]+t;
    x[1]=a[1]+b[1]-t;
    x[2]=a[2]+b[2]-t;
    return x;
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        if(s[l]=='(') tree[idx][1]=1;
        else tree[idx][2]=1;
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=upd(tree[2*idx],tree[2*idx+1]);
    }
}

void solve(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) v.push_back(idx);
    else
    {
        int m=(l+r)/2;
        solve(2*idx,l,m,ql,min(qr,m));
        solve(2*idx+1,m+1,r,max(ql,m+1),qr);
    }
}

int main()
{
    scanf("%s",s+1);
    s[0]='0';
    int n=strlen(s)-1;
    build(1,1,n);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        solve(1,1,n,l,r);
        array<int,3> res={0,0,0};
        for(int x:v) res=upd(res,tree[x]);
        printf("%d\n",2*res[0]);
        v.clear();
    }
    return 0;
}