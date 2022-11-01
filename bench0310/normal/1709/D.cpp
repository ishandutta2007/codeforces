#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> h(N);
vector<int> tree(4*N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=h[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> h[i];
    build(1,1,m);
    int q;
    cin >> q;
    while(q--)
    {
        int ra,ca,rb,cb,k;
        cin >> ra >> ca >> rb >> cb >> k;
        if(ca>cb)
        {
            swap(ra,rb);
            swap(ca,cb);
        }
        int mx=query(1,1,m,ca+1,cb-1);
        auto up=[&](int r)->int{return (r+((n-r)/k)*k);};
        ra=up(ra);
        rb=up(rb);
        if(ra==rb&&((ca-cb)%k)==0&&ra>mx) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}