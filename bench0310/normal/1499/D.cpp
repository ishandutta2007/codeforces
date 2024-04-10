#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=20000000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<int> p(N+1,0);
    for(int i=2;i<=N;i++)
    {
        int t=(i/sieve[i]);
        if(t==1) p[i]=1;
        else p[i]=p[t]+(sieve[t]!=sieve[i]);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int c,d,x;
        cin >> c >> d >> x;
        ll res=0;
        auto solve=[&](int g)
        {
            if((d+x/g)%c) return;
            int a=(d+x/g)/c;
            res+=(1ll<<p[a]);
        };
        for(int g=1;g*g<=x;g++)
        {
            if(x%g) continue;
            solve(g);
            if(g*g!=x) solve(x/g);
        }
        cout << res << "\n";
    }
    return 0;
}