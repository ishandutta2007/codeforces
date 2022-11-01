#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d,m;
    cin >> n >> d >> m;
    vector<ll> a,b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x<=m) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    vector<ll> sumb(b.size()+1,0);
    for(int i=1;i<=(int)b.size();i++) sumb[i]=sumb[i-1]+b[i-1];
    auto solve=[&](int cnt)->ll
    {
        return sumb[min((int)b.size(),(cnt+d+1-1)/(d+1))];
    };
    ll res=solve(n);
    ll sum=0;
    for(int i=0;i<(int)a.size();i++)
    {
        sum+=a[i];
        res=max(res,sum+solve(n-(i+1)));
    }
    cout << res << "\n";
    return 0;
}