#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
const ll inf=(1ll<<60);
vector<ll> tree(4*N,0);
vector<ll> lazy(4*N,0);

void push(int idx)
{
    for(int i=0;i<2;i++)
    {
        tree[2*idx+i]+=lazy[idx];
        lazy[2*idx+i]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,ll val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return -inf;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) cin >> h[i];
    vector<int> b(n+1,0);
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<ll> dp(n+1,0);
    stack<int> s;
    s.push(0);
    for(int i=1;i<=n;i++)
    {
        update(1,0,n,i-1,i-1,b[i]);
        while(h[s.top()]>h[i])
        {
            int r=s.top();
            s.pop();
            int l=s.top();
            update(1,0,n,l,r-1,-b[r]+b[i]);
        }
        s.push(i);
        dp[i]=query(1,0,n,0,i-1);
        update(1,0,n,i,i,dp[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}