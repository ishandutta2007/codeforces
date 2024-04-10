#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> tree(4*N,0);

void pull(int idx){tree[idx]=tree[2*idx]+tree[2*idx+1];}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=1;
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void update(int idx,int l,int r,int pos)
{
    if(l==r) tree[idx]=0;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        pull(idx);
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
    int z;
    cin >> z;
    while(z--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        s="$"+s; t="$"+t;
        vector<int> v[26];
        for(int i=n;i>=1;i--) v[s[i]-'a'].push_back(i);
        ll res=ll(n)*n;
        build(1,1,n);
        ll sum=0;
        for(int m=0;m<n;m++)
        {
            int c=(t[m+1]-'a');
            for(int j=0;j<c;j++)
            {
                if(!v[j].empty())
                {
                    int p=query(1,1,n,1,v[j].back());
                    res=min(res,sum+p-1);
                }
            }
            if(v[c].empty()) break;
            int x=v[c].back();
            v[c].pop_back();
            sum+=(x-(m+1));
            int tmp=(n-x)-query(1,1,n,x+1,n);
            sum+=tmp;
            update(1,1,n,x);
        }
        if(res==ll(n)*n) res=-1;
        cout << res << "\n";
    }
    return 0;
}