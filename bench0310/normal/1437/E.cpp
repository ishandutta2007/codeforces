#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(vector<ll> a,ll l,ll r)
{
    int n=a.size();
    for(int i=0;i<n;i++) a[i]-=(i+1);
    r=r-n-1;
    const int inf=(1<<30);
    vector<int> best(n+1,inf);
    best[0]=-inf;
    for(int x:a)
    {
        if(!(l<=x&&x<=r)) continue;
        int one=0,two=n;
        while(one<two-1)
        {
            int mid=(one+two)/2;
            if(best[mid]>x) two=mid;
            else one=mid;
        }
        best[two]=x;
    }
    int res=0;
    for(int i=1;i<=n;i++) if(best[i]<inf) res=i;
    return n-res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ll> a(n+2,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    const ll inf=2000000000;
    a[0]=-inf;
    a[n+1]=inf;
    vector<ll> bad={0};
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        bad.push_back(x);
    }
    bad.push_back(n+1);
    bool ok=1;
    int res=0;
    for(int i=0;i<(int)bad.size()-1;i++)
    {
        if(bad[i]+1==bad[i+1]) ok&=(a[bad[i]]<a[bad[i+1]]);
        else
        {
            vector<ll> tmp;
            for(int j=bad[i]+1;j<bad[i+1];j++) tmp.push_back(a[j]);
            if(a[bad[i+1]]-a[bad[i]]-1<bad[i+1]-bad[i]-1) ok=0;
            else res+=solve(tmp,a[bad[i]],a[bad[i+1]]);
        }
    }
    if(ok) cout << res << "\n";
    else cout << "-1\n";
    return 0;
}