#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ll> c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    sort(c.begin(),c.end());
    int neg=0;
    for(ll a:c) neg+=(a<0);
    k=max(1,min(k+1,neg));
    vector<ll> sum(n,0);
    sum[n-1]=c[n-1];
    for(int i=n-2;i>=0;i--) sum[i]=c[i]+sum[i+1];
    vector<ll> val(n,0);
    val[n-1]=c[n-1];
    for(int i=n-2;i>=0;i--) val[i]=val[i+1]+sum[i];
    ll one=0;
    ll res=val[0]-sum[0];
    for(int i=0;i<n;i++)
    {
        one+=(i/k)*c[i];
        if(i==n-1) res=max(res,one);
        else
        {
            res=max(res,one+(i/k)*sum[i+1]+val[i+1]);
            if(((i+1)%k)!=0) res=max(res,one+((i/k)-1)*sum[i+1]+val[i+1]);
        }
    }
    cout << res << "\n";
    return 0;
}