#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return N;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+2];
    for(int i=1;i<=n;i++) v[i].push_back(0);
    vector<int> val(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        v[a].push_back(i);
        val[i]=query(1,1,n,1,a-1);
        update(1,1,n,a,i);
    }
    v[n+1]={0};
    int res=1;
    if((int)v[1].size()<n+1)
    {
        for(int i=1;i<=n+1;i++)
        {
            bool ok=0;
            for(int j=0;j<(int)v[i].size()-1;j++) ok|=(val[v[i][j+1]]>v[i][j]);
            ok|=(query(1,1,n,1,i-1)>v[i].back());
            if(ok) res++;
            else break;
        }
    }
    
    cout << res << "\n";
    return 0;
}