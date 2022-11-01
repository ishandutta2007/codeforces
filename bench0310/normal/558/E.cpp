#include <bits/stdc++.h>

using namespace std;

const int N=100005;
int n;
char s[N];
vector<vector<int>> tree(4*N,vector<int>(26,0));
vector<int> lazy(4*N,-1);
vector<int> cnt(26,0);
vector<array<int,3>> now; //idx,l,r

void build(int idx,int l,int r)
{
    if(l==r) tree[idx][s[l]-'a']=1;
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        for(int i=0;i<26;i++) tree[idx][i]=tree[2*idx][i]+tree[2*idx+1][i];
    }
}

void push(int idx,int l,int r)
{
    if(lazy[idx]==-1) return;
    for(int i=0;i<26;i++) tree[2*idx][i]=tree[2*idx+1][i]=0;
    int m=(l+r)/2;
    int x=(lazy[idx]==0)?(m-l+1):(r-(m+1)+1);
    vector<int> t=tree[idx];
    for(int i=0;i<26;i++)
    {
        int a=min(x,t[i]);
        x-=a;
        t[i]-=a;
        tree[2*idx+lazy[idx]][i]+=a;
    }
    for(int i=0;i<26;i++) tree[2*idx+1-lazy[idx]][i]+=t[i];
    lazy[2*idx]=lazy[2*idx+1]=lazy[idx];
    lazy[idx]=-1;
}

void extract(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        for(int i=0;i<26;i++) cnt[i]+=tree[idx][i];
        now.push_back({idx,l,r});
    }
    else
    {
        push(idx,l,r);
        int m=(l+r)/2;
        extract(2*idx,l,m,ql,min(qr,m));
        extract(2*idx+1,m+1,r,max(ql,m+1),qr);
    }
}

void repair(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) return;
    int m=(l+r)/2;
    repair(2*idx,l,m,ql,min(qr,m));
    repair(2*idx+1,m+1,r,max(ql,m+1),qr);
    for(int i=0;i<26;i++) tree[idx][i]=tree[2*idx][i]+tree[2*idx+1][i];
}

void update(int ql,int qr,int t)
{
    extract(1,1,n,ql,qr);
    int x=0;
    if(t==1) reverse(now.begin(),now.end());
    for(auto [idx,l,r]:now)
    {
        for(int i=0;i<26;i++) tree[idx][i]=0;
        int sz=r-l+1;
        while(sz>0)
        {
            while(cnt[x]==0) x++;
            int a=min(sz,cnt[x]);
            cnt[x]-=a;
            sz-=a;
            tree[idx][x]+=a;
        }
        lazy[idx]=t;
    }
    repair(1,1,n,ql,qr);
    now.clear();
}

void solve(int idx,int l,int r)
{
    if(l==r)
    {
        int x;
        for(int i=0;i<26;i++) if(tree[idx][i]==1) x=i;
        printf("%c",x+'a');
    }
    else
    {
        push(idx,l,r);
        int m=(l+r)/2;
        solve(2*idx,l,m);
        solve(2*idx+1,m+1,r);
    }
}

int main()
{
    int q;
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    build(1,1,n);
    while(q--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        update(a,b,1-c);
    }
    solve(1,1,n);
    printf("\n");
    return 0;
}