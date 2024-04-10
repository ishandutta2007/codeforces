#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sieve(n+1,0);
    for(int i=1;i<=n;i++) sieve[i]=i;
    vector<int> bucket[n+1];
    for(ll i=2;i<=n;i++)
    {
        if(i!=2&&(i%2)==0&&sieve[i/2]==i/2) bucket[i/2].push_back(i);
        else bucket[sieve[i]].push_back(i);
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=n;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<array<int,2>> res;
    for(int i=n;i>=3;i--)
    {
        if(bucket[i].size()<=1) continue;
        vector<int> v;
        for(int a:bucket[i]) if(a!=2*i) v.push_back(a);
        if(v.size()&1) v.push_back(2*i);
        else bucket[2].push_back(2*i);
        for(int j=0;j<(int)v.size();j+=2) res.push_back({v[j],v[j+1]});
    }
    for(int i=0;i+1<(int)bucket[2].size();i+=2) res.push_back({bucket[2][i],bucket[2][i+1]});
    cout << res.size() << "\n";
    for(auto [a,b]:res) cout << a << " " << b << "\n";
    return 0;
}