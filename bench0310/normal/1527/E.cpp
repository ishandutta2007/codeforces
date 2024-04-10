#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int inf=35000*35000/2;

struct ST
{
    int n;
    vector<int> tree;
    vector<int> lazy;
    ST(int m)
    {
        n=m;
        tree.assign(4*(n+5),0);
        lazy.assign(4*(n+5),0);
    }
    void push(int idx)
    {
        for(int i=0;i<2;i++)
        {
            tree[2*idx+i]+=lazy[idx];
            lazy[2*idx+i]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    void update(int idx,int l,int r,int ql,int qr,int x)
    {
        if(ql>qr) return;
        if(l==ql&&r==qr)
        {
            tree[idx]+=x;
            lazy[idx]+=x;
        }
        else
        {
            int m=(l+r)/2;
            push(idx);
            update(2*idx,l,m,ql,min(qr,m),x);
            update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    int query(int idx,int l,int r,int ql,int qr)    
    {
        if(ql>qr) return inf;
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        push(idx);
        return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    void upd(int l,int r,int x){update(1,0,n,l,r,x);}
    int qry(int l,int r){return query(1,0,n,l,r);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ST> st(k+1,ST(n));
    vector<int> prv(n+1,0);
    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        for(int j=0;j<=k;j++) st[j].upd(0,prv[a]-1,-prv[a]+i);
        for(int j=1;j<=k;j++) dp[i][j]=st[j-1].qry(0,i-1);
        for(int j=0;j<=k;j++) st[j].upd(i,i,dp[i][j]);
        prv[a]=i;
    }
    cout << dp[n][k] << "\n";
    return 0;
}