#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<int> a(N,0);
vector<array<array<int,2>,2>> tree(4*N,{array<int,2>{0,0},array<int,2>{0,0}});
vector<bool> lazy(4*N,0);

void tmerge(int idx)
{
    for(int i=0;i<=1;i++) tree[idx][i][i]=tree[2*idx][i][i]+tree[2*idx+1][i][i];
    tree[idx][0][1]=tree[idx][1][0]=0;
    for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) if(i<=j) tree[idx][0][1]=max(tree[idx][0][1],tree[2*idx][0][i]+tree[2*idx+1][j][1]);
    for(int i=0;i<=1;i++) for(int j=0;j<=1;j++) if(i>=j) tree[idx][1][0]=max(tree[idx][1][0],tree[2*idx][1][i]+tree[2*idx+1][j][0]);
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx][a[l]][a[l]]=1;
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tmerge(idx);
    }
}

void push(int idx)
{
    if(lazy[idx]==1)
    {
        for(int i=2*idx;i<=2*idx+1;i++)
        {
            swap(tree[i][0][0],tree[i][1][1]);
            swap(tree[i][0][1],tree[i][1][0]);
            lazy[i]=!lazy[i];
        }
        lazy[idx]=0;
    }
}

void update(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        swap(tree[idx][0][0],tree[idx][1][1]);
        swap(tree[idx][0][1],tree[idx][1][0]);
        lazy[idx]=!lazy[idx];
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m));
        update(2*idx+1,m+1,r,max(ql,m+1),qr);
        tmerge(idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    s="$"+s;
    for(int i=1;i<=n;i++) a[i]=(s[i]=='7');
    build(1,1,n);
    while(m--)
    {
        string t;
        cin >> t;
        if(t[0]=='s')
        {
            int l,r;
            cin >> l >> r;
            update(1,1,n,l,r);
        }
        else cout << max({tree[1][0][0],tree[1][1][1],tree[1][0][1]}) << "\n";
    }
    return 0;
}