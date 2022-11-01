#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000000;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto factorise=[&](int a)->vector<array<int,2>>
    {
        vector<array<int,2>> p;
        while(a>1)
        {
            int r=sieve[a];
            int c=0;
            while(sieve[a]==r)
            {
                c++;
                a/=r;
            }
            p.push_back({r,c});
        }
        return p;
    };
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> s(N+1,1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        for(auto [p,c]:factorise(a[i])) s[p]+=c;
    }
    vector<int> nxt[N+1];
    vector<int> h(N+1,0);
    for(int i=1;i<=N;i++) nxt[i].assign(2*s[i]+1,n+1);
    multiset<int> bad={n+1};
    vector<int> lim(N+1,n+1);
    for(int i=2;i<=N;i++) if(sieve[i]==i&&s[i]>1) bad.insert(lim[i]);
    string b;
    cin >> b;
    b="$"+b;
    ll res=0;
    for(int i=n;i>=1;i--)
    {
        for(auto [p,c]:factorise(a[i]))
        {
            nxt[p][h[p]+s[p]]=i;
            for(int j=0;j<c;j++)
            {
                if(b[i]=='*') h[p]--;
                else h[p]++;
                nxt[p][h[p]+s[p]]=i;
            }
            bad.erase(bad.find(lim[p]));
            lim[p]=nxt[p][h[p]-1+s[p]];
            bad.insert(lim[p]);
        }
        int r=(*bad.begin())-1;
        res+=(r-i+1);
    }
    cout << res << "\n";
    return 0;
}