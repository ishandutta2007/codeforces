#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> sieve(n+1,1);
    vector<int> primes;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i]==0) continue;
        primes.push_back(i);
        for(int j=i*i;j<=n;j+=i) sieve[j]=0;
    }
    vector<int> res;
    for(int p:primes)
    {
        int a=p;
        while(a<=n)
        {
            res.push_back(a);
            a*=p;
        }
    }
    cout << res.size() << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    return 0;
}