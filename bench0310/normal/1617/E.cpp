#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto f=[&](int a)->int
    {
        int b=(1<<(31-countl_zero(uint32_t(a))));
        if(b==a) return 0;
        else return 2*b-a;
    };
    vector<array<int,2>> e;
    function<int(int)> depth=[&](int a)->int
    {
        int d=(a==0?0:depth(f(a))+1);
        e.push_back({d,a});
        return d;
    };
    array<int,3> res={-1,0,0};
    map<int,array<int,2>> m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        depth(a);
        m[a]={0,i};
    }
    ranges::sort(e,greater<>());
    e.erase(unique(e.begin(),e.end()),e.end());
    e.pop_back();
    for(auto [t,a]:e)
    {
        auto [d,i]=m[a];
        int b=f(a);
        auto [u,j]=m[b];
        if(j!=0) res=max(res,{d+1+u,i,j});
        m[b]=max(m[b],{d+1,i});
    }
    cout << res[1] << " " << res[2] << " " << res[0] << "\n";
    return 0;
}