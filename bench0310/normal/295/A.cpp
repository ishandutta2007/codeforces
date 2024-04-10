#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,3>> ops(m+1,{0,0,0});
    for(int i=1;i<=m;i++) for(int j=0;j<3;j++) cin >> ops[i][j];
    vector<int> one(m+2,0);
    while(k--)
    {
        int x,y;
        cin >> x >> y;
        one[x]++;
        one[y+1]--;
    }
    vector<ll> two(n+2,0);
    int s=0;
    for(int i=1;i<=m;i++)
    {
        s+=one[i];
        auto [l,r,d]=ops[i];
        two[l]+=((ll)s*d);
        two[r+1]-=((ll)s*d);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=two[i];
        cout << a[i]+res << " \n"[i==n];
    }
    return 0;
}