#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
vector<int> v[N];
vector<int> tin(N,0);
vector<int> tout(N,0);
int tcnt=1;
vector<int> one(4*N,-1);
vector<int> lazy(4*N,-1);
vector<int> two(4*N,0);

void mx(int &a,int b)
{
    a=max(a,b);
}

void push(int idx)
{
    mx(one[2*idx],lazy[idx]);
    mx(lazy[2*idx],lazy[idx]);
    mx(one[2*idx+1],lazy[idx]);
    mx(lazy[2*idx+1],lazy[idx]);
}

void updone(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        one[idx]=val;
        lazy[idx]=val;
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        updone(2*idx,l,m,ql,min(qr,m),val);
        updone(2*idx+1,m+1,r,max(ql,m+1),qr,val);
    }
}

int qone(int idx,int l,int r,int pos)
{
    if(l==r) return one[idx];
    push(idx);
    int m=(l+r)/2;
    if(pos<=m) return qone(2*idx,l,m,pos);
    else return qone(2*idx+1,m+1,r,pos);
}

void updtwo(int idx,int l,int r,int pos,int val)
{
    if(l==r) two[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) updtwo(2*idx,l,m,pos,val);
        else updtwo(2*idx+1,m+1,r,pos,val);
        two[idx]=max(two[2*idx],two[2*idx+1]);
    }
}

int qtwo(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return two[idx];
    int m=(l+r)/2;
    return max(qtwo(2*idx,l,m,ql,min(qr,m)),qtwo(2*idx+1,m+1,r,max(ql,m+1),qr));
}

void dfs(int a,int p=-1)
{
    tin[a]=tcnt++;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
    }
    tout[a]=tcnt-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int t,a;
        scanf("%d%d",&t,&a);
        if(t==1) updone(1,1,n,tin[a],tout[a],i);
        else if(t==2) updtwo(1,1,n,tin[a],i);
        else if(t==3) printf("%d\n",(qone(1,1,n,tin[a])>qtwo(1,1,n,tin[a],tout[a])));
    }
    return 0;
}