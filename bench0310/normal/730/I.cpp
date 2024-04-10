#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,n;
    cin >> n >> a >> b;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++) cin >> v[i][0];
    for(int i=0;i<n;i++) cin >> v[i][1];
    for(int i=0;i<n;i++) v[i][2]=i+1;
    sort(v.begin(),v.end(),greater<>());
    ll res=0;
    vector<int> g(n+1,0);
    set<array<int,2>> one,ta,tb;
    for(int i=0;i<a;i++)
    {
        res+=v[i][0];
        one.insert({v[i][1]-v[i][0],i});
        g[v[i][2]]=1;
    }
    for(int i=a;i<n;i++)
    {
        ta.insert({v[i][0],i});
        tb.insert({v[i][1],i});
    }
    auto go_one=[&]()
    {
        auto [y,i]=(*tb.rbegin());
        res+=y;
        g[v[i][2]]=2;
        ta.erase({v[i][0],i});
        tb.erase({v[i][1],i});
    };
    auto go_two=[&]()
    {
        auto [x,i]=(*ta.rbegin());
        res+=x;
        g[v[i][2]]=1;
        ta.erase({v[i][0],i});
        tb.erase({v[i][1],i});
        auto [val,j]=(*one.rbegin());
        res+=val;
        g[v[j][2]]=2;
        one.erase({val,j});
        one.insert({v[i][1]-v[i][0],i});
    };
    while(b--)
    {
        if(a==0) go_one();
        else
        {
            ll s_one=(*tb.rbegin())[0];
            ll s_two=(*one.rbegin())[0]+(*ta.rbegin())[0];
            if(s_one>=s_two) go_one();
            else go_two();
        }
    }
    cout << res << "\n";
    for(int i=1;i<=n;i++) if(g[i]==1) cout << i << " ";
    cout << "\n";
    for(int i=1;i<=n;i++) if(g[i]==2) cout << i << " ";
    cout << "\n";
    return 0;
}