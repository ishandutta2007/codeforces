#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<int> s[n+1];
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;
        s[t].insert(i);
    }
    int res=n-1;
    for(int i=1;i<=m;i++)
    {
        for(int a:s[i]) if(s[i].find(a+1)!=s[i].end()) res--;
    }
    cout << res << "\n";
    for(int i=0;i<m-1;i++)
    {
        int a,b;
        cin >> a >> b;
        if(s[a].size()<s[b].size()) swap(s[a],s[b]);
        for(int x:s[b])
        {
            if(s[a].find(x-1)!=s[a].end()) res--;
            if(s[a].find(x+1)!=s[a].end()) res--;
        }
        for(int x:s[b]) s[a].insert(x);
        cout << res << "\n";
    }
    return 0;
}