#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,h,m,k;
    cin >> n >> h >> m >> k;
    vector<int> v(n);
    vector<int> u(n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp >> v[i];
        u[i]=v[i];
    }
    ranges::sort(v);
    auto cnt=[&](int l,int r)->int{return (ranges::upper_bound(v,r)-ranges::lower_bound(v,l));};
    auto c=[&](int t)->int
    {
        if(t-k>=0) return cnt(t-k+1,t-1);
        else return (cnt(t-k+1+m,m)+cnt(0,t-1));
    };
    auto e=[&](int t)->int
    {
        t%=(m/2);
        return (c(t)+c(t+m/2));
    };
    array<int,2> res={n+1,0};
    for(int t:v) res=min(res,{e(t),t%(m/2)});
    int t=res[1];
    cout << res[0] << " " << t << "\n";
    for(int i=1;int x:u)
    {
        bool ok=1;
        if(t-k>=0) ok&=(!(t-k+1<=x&&x<=t-1));
        else ok&=(!(t-k+1+m<=x||x<=t-1));
        ok&=(!(t+m/2-k+1<=x&&x<=t+m/2-1));
        if(ok==0) cout << i << " ";
        i++;
    }
    cout << "\n";
    return 0;
}