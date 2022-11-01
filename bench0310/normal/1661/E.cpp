#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos)
{
    if(l==r) tree[idx]++;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        tree[idx]++;
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
    cin >> n;
    vector<string> v(3);
    for(int i=0;i<3;i++) cin >> v[i];
    vector<string> s(n+1,"");
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) s[i]+=v[j][i-1];
    vector<int> prv(n+1,0);
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int on=ranges::count(s[i],'1');
        int close=0;
        if(i<n)
        {
            for(int j=0;j<3;j++) close+=(s[i][j]=='1'&&s[i+1][j]=='0');
            if(s[i]!="101") sum[i]=sum[i-1]+(on>=1&&close==on);
        }
        if(s[i]=="101")
        {
            if(s[i-1]=="101") prv[i]=prv[i-1];
            if(s[i-1]=="111") prv[i]=i-1;
            if(i<n) sum[i]=sum[i-1]+close;
        }
    }
    int q;
    cin >> q;
    vector<array<int,2>> queries[n+1];
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        queries[r].push_back({l,i});
    }
    vector<int> res(q+1,0);
    for(int i=1;i<=n;i++)
    {
        int c=int(s[i]!="000")+(s[i]=="101");
        for(auto [l,id]:queries[i])
        {
            res[id]=c+sum[i-1]-sum[l-1]-query(1,1,n,l,i);
            if(s[i]=="101") res[id]-=(prv[i]>=l);
        }
        if(i<n&&s[i]=="101"&&(s[i+1][0]=='0'||s[i+1][2]=='0')&&prv[i]>=1) update(1,1,n,prv[i]);
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}