#include <bits/stdc++.h>

using namespace std;

const int N=400005;
vector<int> v[N];
vector<int> col(N);
long long tree[4*N];
long long lazy[4*N];
vector<int> tin(N);
vector<int> tout(N);
int tcnt=1;

void push(int idx)
{
    if(lazy[idx]==0) return;
    tree[2*idx]=lazy[idx];
    lazy[2*idx]=lazy[idx];
    tree[2*idx+1]=lazy[idx];
    lazy[2*idx+1]=lazy[idx];
    lazy[idx]=0;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=(1ll<<col[l]);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=tree[2*idx]|tree[2*idx+1];
    }
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]=(1ll<<val);
        lazy[idx]=(1ll<<val);
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=tree[2*idx]|tree[2*idx+1];
    }
}

long long query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    push(idx);
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))|query(2*idx+1,m+1,r,max(ql,m+1),qr);
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

void in(int &a)
{
    a=0;
    bool s=0;
    char c=_getchar_nolock();
	while(!isdigit(c))
	{
		if(c=='-') s=1;
		c=_getchar_nolock();
	}
    while(isdigit(c))
    {
        a=10*a+(c-'0');
		c=_getchar_nolock();
    }
    if(s) a=-a;
}

void out(int a)
{
    if(a<0)
	{
		putchar('-');
		a=-a;
    }
	if(a>=10) out(a/10);
	putchar((a%10)+'0');
}

int main()
{
    int n,m;
    in(n); in(m);
    vector<int> x(n+1,0);
    for(int i=1;i<=n;i++) in(x[i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        in(a); in(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++) col[tin[i]]=x[i];
    build(1,1,n);
    while(m--)
    {
        int t;
        in(t);
        if(t==1)
        {
            int a,c;
            in(a); in(c);
            update(1,1,n,tin[a],tout[a],c);
        }
        else if(t==2)
        {
            int a;
            in(a);
            out(__builtin_popcountll(query(1,1,n,tin[a],tout[a])));
            putchar('\n');
        }
    }
    return 0;
}