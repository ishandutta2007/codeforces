#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto f=[&](int a)
    {
        vector<int> r;
        while(a>1)
        {
            int p=sieve[a];
            while(sieve[a]==p) a/=p;
            r.push_back(p);
        }
        return r;
    };
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> nxt(N+1,n+1);
    int r=n;
    vector<vector<int>> to(n+2,vector<int>(17,n+1));
    for(int i=n;i>=1;i--)
    {
        vector<int> p=f(a[i]);
        for(int x:p)
        {
            r=min(r,nxt[x]-1);
            nxt[x]=i;
        }
        to[i][0]=r+1;
        for(int j=1;j<17;j++) to[i][j]=to[to[i][j-1]][j-1];
    }
    while(q--)
    {
        int l;
        cin >> l >> r;
        int res=0;
        for(int j=16;j>=0;j--)
        {
            if(to[l][j]<=r)
            {
                l=to[l][j];
                res+=(1<<j);
            }
        }
        cout << res+1 << "\n";
    }
    return 0;
}