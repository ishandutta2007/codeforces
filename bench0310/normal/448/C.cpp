#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=5005;
int n;
vector<array<int,2>> tree(4*N,{0,0});
vector<int> a(N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]={a[l],l};
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

array<int,2> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {(1<<30),0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

ll solve(int l,int r,int h)
{
    if(l>r) return 0;
    auto [m,id]=query(1,1,n,l,r);
    return min((ll)r-l+1,m-h+solve(l,id-1,m)+solve(id+1,r,m));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    cout << solve(1,n,0) << "\n";
    return 0;
}