#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
const array<array<ll,2>,2> zero={array<ll,2>{0,0},array<ll,2>{0,0}};
vector<array<array<ll,2>,2>> tree(4*N,zero);
vector<int> val(N);

void stmerge(int idx)
{
    tree[idx]=zero;
    for(int l=0;l<=1;l++)
    {
        for(int r=0;r<=1;r++)
        {
            tree[idx][l][r]=max(tree[2*idx][l][0]+tree[2*idx+1][1][r],tree[2*idx][l][1]+tree[2*idx+1][0][r]);
        }
    }
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx][0][0]=val[l];
        tree[idx][1][1]=-val[l];
        tree[idx][0][1]=tree[idx][1][0]=0;
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        stmerge(idx);
    }
}

void update(int idx,int l,int r,int pos)
{
    if(l==r)
    {
        tree[idx][0][0]=val[l];
        tree[idx][1][1]=-val[l];
        tree[idx][0][1]=tree[idx][1][0]=0;
    }
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        stmerge(idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        for(int i=1;i<=n;i++) cin >> val[i];
        build(1,1,n);
        cout << tree[1][0][0] << "\n";
        while(q--)
        {
            int a,b;
            cin >> a >> b;
            swap(val[a],val[b]);
            update(1,1,n,a);
            update(1,1,n,b);
            cout << tree[1][0][0] << "\n";
        }
    }
    return 0;
}