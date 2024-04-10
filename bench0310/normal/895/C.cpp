#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int N=70;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    vector<int> h(N+1,-1);
    int id=0;
    for(int i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        h[i]=id++;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<int> basis(id,0);
    int sz=0;
    auto add=[&](int m)
    {
        for(int i=0;i<id;i++)
        {
            if((m&(1<<i))==0) continue;
            if(basis[i]!=0) m^=basis[i];
            else
            {
                basis[i]=m;
                sz++;
                break;
            }
        }
    };
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        int m=0;
        while(a>1)
        {
            m^=(1<<h[sieve[a]]);
            a/=sieve[a];
        }
        add(m);
    }
    int res=1;
    const int mod=1000000007;
    for(int i=0;i<n-sz;i++) res=(2*res)%mod;
    res=(res-1+mod)%mod;
    cout << res << "\n";
    return 0;
}