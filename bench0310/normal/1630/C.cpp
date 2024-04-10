#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> tree(4*N,-N);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return -N;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    vector<int> one(n+1,1);
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        one[i]=(p[a]==0);
        dp[i]=dp[i-1];
        if(one[i]==0)
        {
            dp[i]=max(i+dp[p[a]]-p[a]-one[p[a]],query(1,1,n,p[a]+1,i-1)+i-1);
        }
        update(1,1,n,i,dp[i]-i);
        p[a]=i;
    }
    cout << dp[n] << "\n";
    return 0;
}