#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    const int N=100000;
    const int S=320;
    int res=0;
    auto go=[&](vector<ll> &v,int x)
    {
        ranges::sort(v);
        int l=0;
        int sz=v.size();
        while(l<sz)
        {
            int r=l;
            while(r+1<sz&&v[r+1]==v[l]) r++;
            res=max(res,r-l+1+x);
            l=r+1;
        }
    };
    vector<ll> v(n,0);
    for(int d=-S;d<=S;d++)
    {
        for(int i=1;i<=n;i++) v[i-1]=(a[i]-i*d);
        go(v,0);
    }
    for(int i=1;i<=n;i++)
    {
        vector<ll> u;
        for(int j=i+1;j<=n&&(a[i]+(S+1)*(j-i)<=N||a[i]-(S+1)*(j-i)>=1);j++) if(((a[j]-a[i])%(j-i))==0) u.push_back((a[j]-a[i])/(j-i));
        go(u,1);
    }
    cout << n-res << "\n";
    return 0;
}