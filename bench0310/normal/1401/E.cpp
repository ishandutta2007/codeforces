#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000000;
vector<int> tree(4*(N+5),0);

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
    int n,m;
    cin >> n >> m;
    vector<array<int,4>> v; //x,tp,y1,y2
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int y,x1,x2;
        cin >> y >> x1 >> x2;
        if(x1==0&&x2==N) res++;
        v.push_back({x1,0,y,y});
        v.push_back({x2,2,y,y});
    }
    for(int i=0;i<m;i++)
    {
        int x,y1,y2;
        cin >> x >> y1 >> y2;
        if(y1==0&&y2==N) res++;
        v.push_back({x,1,y1,y2});
    }
    sort(v.begin(),v.end());
    for(auto [x,tp,y1,y2]:v)
    {
        if(tp==0||tp==2) update(1,0,N,y1,(tp==0?1:-1));
        else res+=query(1,0,N,y1,y2);
    }
    cout << res+1 << "\n";
    return 0;
}