#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=10000000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto odd=[&](int a)->vector<int>
    {
        vector<int> v;
        while(a>1)
        {
            int p=sieve[a];
            int pw=0;
            while((a%p)==0)
            {
                a/=p;
                pw^=1;
            }
            if(pw==1) v.push_back(p);
        }
        return v;
    };
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int res=1;
        set<vector<int>> s;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            vector<int> v=odd(a);
            if(s.find(v)!=s.end())
            {
                s.clear();
                res++;
            }
            s.insert(v);
        }
        cout << res << "\n";
    }
    return 0;
}