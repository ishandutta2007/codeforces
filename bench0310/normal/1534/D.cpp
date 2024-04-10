#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto q=[&](int a)->vector<int>
    {
        cout << "? " << a << "\n";
        cout.flush();
        vector<int> d(n+1,0);
        for(int i=1;i<=n;i++) cin >> d[i];
        return d;
    };
    vector<int> d[n+1];
    d[1]=q(1);
    vector<int> v[2];
    for(int i=1;i<=n;i++) v[d[1][i]&1].push_back(i);
    if(v[0].size()>v[1].size()) swap(v[0],v[1]);
    for(int a:v[0]) if(d[a].empty()) d[a]=q(a);
    cout << "!\n";
    for(int a:v[0])
    {
        for(int i=1;i<=n;i++) if(d[a][i]==1) cout << a << " " << i << "\n";
    }
    cout.flush();
    return 0;
}