#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,2>> v(n+1,{0,0});
    for(int i=1;i<=n;i++) cin >> v[i][0] >> v[i][1];
    sort(v.begin(),v.end(),[](const array<ll,2> &a,const array<ll,2> &b){return (a[1]<b[1]);});
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) a[i]=v[i][0];
    vector<ll> b(n+1,0);
    for(int i=1;i<=n;i++) b[i]=v[i][1];
    ll res=0;
    ll bought=0;
    int idx=n;
    for(int i=1;i<=idx;i++)
    {
        while(b[i]>bought&&i<idx)
        {
            ll c=min(b[i]-bought,a[idx]);
            res+=(2*c);
            a[idx]-=c;
            bought+=c;
            if(a[idx]==0) idx--;
        }
        ll req=max(0ll,b[i]-bought);
        ll two=min(req,a[i]);
        res+=(2*two);
        a[i]-=two;
        bought+=two;
        ll one=a[i];
        res+=one;
        a[i]-=one;
        bought+=one;
    }
    cout << res << "\n";
    return 0;
}