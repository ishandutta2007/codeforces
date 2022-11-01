#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=10000000;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(ll i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int n;
    cin >> n;
    vector<int> v;
    vector<int> sum(N+1,0);
    while(n--)
    {
        ll x;
        cin >> x;
        while(x>1)
        {
            int p=sieve[x];
            sum[p]++;
            while((x%p)==0) x/=p;
        }
    }
    for(int i=2;i<=N;i++) sum[i]+=sum[i-1];
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << sum[min(r,N)]-sum[min(N,l-1)] << "\n";
    }
    return 0;
}