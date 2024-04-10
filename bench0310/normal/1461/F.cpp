#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) cin >> v[i];
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if((int)s.find('+')!=-1&&s.back()=='-') s.pop_back();
    string res(n+1,'$');
    auto out=[&]()
    {
        for(int i=1;i<=n;i++)
        {
            cout << v[i];
            if(i<n) cout << res[i];
        }
        cout << "\n";
        exit(0);
    };
    if(s.size()==1)
    {
        res=string(n+1,s[0]);
        out();
    }
    if(s=="*-")
    {
        bool zero=0;
        for(int i=1;i<=n;i++)
        {
            if(zero==0&&v[i]==0)
            {
                res[i-1]='-';
                zero=1;
            }
            res[i]='*';
        }
        out();
    }
    const int k=54;
    vector<ll> t(n+1,1);
    auto solve=[&](int l,int r)
    {
        ll x=1;
        for(int i=l;i<=r;i++)
        {
            x*=v[i];
            if(x>(1ll<<k)) break;
        }
        if(x==1)
        {
            for(int i=l;i<r;i++) res[i]='+';
            return;
        }
        while(v[l]==1) res[l++]='+';
        while(v[r]==1) res[--r]='+';
        if(x>(1ll<<k))
        {
            for(int i=l;i<r;i++) res[i]='*';
            return;
        }
        t[l-1]=1;
        for(int i=l;i<=r;i++) t[i]=(t[i-1]*v[i]);
        auto p=[&](int a,int b)->ll{return (t[b]/t[a-1]);};
        vector<int> pos={l-1};
        for(int i=l;i<=r;i++) if(v[i]>1) pos.push_back(i);
        int sz=pos.size()-1;
        vector<ll> dp(sz+1,0);
        vector<int> h(sz+1,1);
        for(int i=1;i<=sz;i++)
        {
            for(int j=1;j<=i;j++)
            {
                ll val=dp[j-1]+(pos[j]-pos[j-1]-1)+p(pos[j],pos[i]);
                if(val>dp[i])
                {
                    dp[i]=val;
                    h[i]=j;
                }
            }
        }
        int idx=sz;
        while(idx>0)
        {
            for(int i=pos[h[idx]];i<pos[idx];i++) res[i]='*';
            for(int i=max(l,pos[h[idx]-1]);i<pos[h[idx]];i++) res[i]='+';
            idx=h[idx]-1;
        }
    };
    int l=1;
    while(l<=n)
    {
        if(v[l]==0)
        {
            res[l-1]=res[l]='+';
            l++;
            continue;
        }
        int r=l;
        while(r+1<=n&&v[r+1]!=0) r++;
        solve(l,r);
        l=r+1;
    }
    out();
    return 0;
}