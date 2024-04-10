#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> tree(4*N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=1;
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s="$"+s;
    build(1,1,n);
    auto inc=[&](int l,int r)
    {
        update(1,1,n,l,1);
        if(r+1<=n) update(1,1,n,r+1,-1);
    };
    auto qry=[&](int pos)->int{return query(1,1,n,1,pos);};
    ll res=0;
    vector<int> v[26];
    for(int i=n;i>=1;i--) v[s[i]-'a'].push_back(i);
    for(int i=1;i<=n;i++)
    {
        int now=v[s[n+1-i]-'a'].back();
        v[s[n+1-i]-'a'].pop_back();
        res+=(qry(now)-i);
        inc(1,now);
    }
    cout << res << "\n";
    return 0;
}