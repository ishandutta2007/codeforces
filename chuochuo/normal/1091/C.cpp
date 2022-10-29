#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
set<ll> s;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i) continue;
        if(i*i==n)
        {
            ll last=(n+1-i);
            ll num=(last-1)/i+1;
            ll res=(1+last)*num/2;
            s.insert(res);
        }
        else
        {
            ll last=(n+1-i);
            ll num=(last-1)/i+1;
            ll res=(1+last)*num/2;
            s.insert(res);
            last=(n+1-n/i);
            num=(last-1)/(n/i)+1;
            res=(1+last)*num/2;
            s.insert(res);
        }
    }
    for(auto v:s) printf("%lld ",v);
    return 0;
}