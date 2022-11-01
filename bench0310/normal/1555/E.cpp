#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000000;
vector<int> tree(4*N,0);
vector<int> lazy(4*N,0);

void apply(int idx,int x)
{
    tree[idx]+=x;
    lazy[idx]+=x;
}

void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i][1] >> v[i][2] >> v[i][0];
        v[i][2]--;
    }
    sort(v.begin(),v.end());
    int r=-1;
    int res=(v[n-1][0]-v[0][0]);
    for(int l=0;l<n;l++)
    {
        while(r+1<n&&tree[1]==0)
        {
            r++;
            update(1,1,m-1,v[r][1],v[r][2],1);
        }
        if(tree[1]==0) break;
        res=min(res,v[r][0]-v[l][0]);
        update(1,1,m-1,v[l][1],v[l][2],-1);
    }
    cout << res << "\n";
    return 0;
}