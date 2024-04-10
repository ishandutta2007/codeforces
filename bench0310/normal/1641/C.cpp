#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> ok(N,0);
vector<int> tree(4*N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=ok[l];
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
    int n,q;
    cin >> n >> q;
    vector<array<int,4>> e(q+1);
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=q;i++)
    {
        auto &[t,l,r,x]=e[i];
        cin >> t;
        if(t==0)
        {
            cin >> l >> r >> x;
            if(x==0)
            {
                while(1)
                {
                    auto it=s.lower_bound(l);
                    if(it!=s.end()&&(*it)<=r)
                    {
                        int p=(*it);
                        s.erase(it);
                        ok[p]=i;
                    }
                    else break;
                }
            }
        }
        else cin >> l;
    }
    build(1,1,n);
    vector<int> sick[q+1];
    for(int i=1;i<=q;i++)
    {
        auto [t,l,r,x]=e[i];
        if(t==0&&x==1)
        {
            auto it=s.lower_bound(l);
            it++;
            if(it==s.end()||(*it)>r)
            {
                int m=query(1,1,n,l,r);
                sick[max(m,i)].push_back(*prev(it));
            }
        }
    }
    vector<bool> is_sick(n+1,0);
    for(int i=1;i<=q;i++)
    {
        auto [t,l,r,x]=e[i];
        for(int y:sick[i]) is_sick[y]=1;
        if(t==1)
        {
            if(ok[l]!=0&&ok[l]<=i) cout << "NO\n";
            else if(is_sick[l]) cout << "YES\n";
            else cout << "N/A\n";
        }
    }
    return 0;
}