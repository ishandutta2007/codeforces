#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<array<ll,2>> p(n);
    for(auto &[x,y]:p)
    {
        cin >> x >> y;
        x*=2;
        y*=2;
    }
    if(n==k)
    {
        cout << "-1\n";
        exit(0);
    }
    sort(p.begin(),p.end());
    set<array<ll,2>> opt;
    for(int a=0;a<=k;a++) for(ll b=0;b<=k-a;b++) if(a<=n-1-b) opt.insert({(p[a][0]+p[n-1-b][0])/2,(p[a][1]+p[n-1-b][1])/2});
    vector<array<ll,2>> res;
    for(auto [ox,oy]:opt)
    {
        ll idx=n-1;
        ll c=k;
        for(auto [x,y]:p)
        {
            while(idx>0&&p[idx]>array<ll,2>{2*ox-x,2*oy-y}) idx--;
            if(p[idx]!=array<ll,2>{2*ox-x,2*oy-y}) c--;
        }
        if(c>=0) res.push_back({ox,oy});
    }
    cout << res.size() << "\n";
    for(auto [x,y]:res) cout << (x<0?"-":"") << abs(x/2) << "." << "05"[x&1] << " " << (y<0?"-":"") << abs(y/2) << "." << "05"[y&1] << "\n";
    return 0;
}