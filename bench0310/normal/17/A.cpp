#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<bool> sieve(n+1,1);
    vector<int> primes;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i]==0) continue;
        primes.push_back(i);
        for(int j=i*i;j<=n;j+=i) sieve[j]=0;
    }
    int cnt=0;
    for(int p:primes)
    {
        bool ok=0;
        for(int i=0;i<(int)primes.size()-1;i++) ok|=(primes[i]+primes[i+1]==p-1);
        cnt+=ok;
    }
    if(cnt>=k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}