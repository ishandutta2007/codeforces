#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int inf=(1<<30);

struct SegTree
{
    vector<int> tree;
    int n;
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
        if(ql>qr) return inf;
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    SegTree(int _n)
    {
        n=_n;
        tree.assign(4*(n+5),inf);
    }
    void upd(int pos,int val){update(1,1,n,pos,val);}
    int qry(int ql,int qr){return query(1,1,n,max(ql,1),qr);}
};

void pre(int n,vector<int> &h,vector<int> &sm,vector<int> &lg)
{
    stack<array<int,2>> s;
    s.push({inf,n+1});
    for(int i=n;i>=1;i--)
    {
        while(s.top()[0]<h[i]) s.pop();
        lg[i]=s.top()[1];
        s.push({h[i],i});
    }
    while(!s.empty()) s.pop();
    s.push({0,n+1});
    for(int i=n;i>=1;i--)
    {
        while(s.top()[0]>h[i]) s.pop();
        sm[i]=s.top()[1];
        s.push({h[i],i});
    }
}

void rv(int n,vector<int> &a)
{
    for(int i=1;i<=n;i++)
    {
        if(i<n+1-i) swap(a[i],a[n+1-i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) cin >> h[i];
    vector<int> nxtsm(n+1,0);
    vector<int> nxtlg(n+1,0);
    pre(n,h,nxtsm,nxtlg);
    rv(n,h);
    vector<int> prvsm(n+1,0);
    vector<int> prvlg(n+1,0);
    pre(n,h,prvsm,prvlg);
    rv(n,h);
    rv(n,prvsm);
    rv(n,prvlg);
    for(int i=1;i<=n;i++)
    {
        prvsm[i]=n+1-prvsm[i];
        prvlg[i]=n+1-prvlg[i];
    }
    SegTree up(n);
    SegTree down(n);
    vector<int> dp(n+1,inf);
    vector<int> rmup[n+2];
    vector<int> rmdown[n+2];
    auto add=[&](int i)
    {
        up.upd(i,dp[i]);
        down.upd(i,dp[i]);
        rmup[nxtsm[i]].push_back(i);
        rmdown[nxtlg[i]].push_back(i);
    };
    dp[1]=0;
    add(1);
    for(int i=2;i<=n;i++)
    {
        dp[i]=min(dp[i],up.qry(prvsm[i],i-1)+1);
        dp[i]=min(dp[i],down.qry(prvlg[i],i-1)+1);
        for(int x:rmup[i]) up.upd(x,inf);
        for(int x:rmdown[i]) down.upd(x,inf);
        add(i);
    }
    cout << dp[n] << "\n";
    return 0;
}