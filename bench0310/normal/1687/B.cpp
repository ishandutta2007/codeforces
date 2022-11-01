#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> edges;
    for(int i=1;i<=m;i++)
    {
        string s(m,'0');
        s[i-1]='1';
        cout << "? " << s << endl;
        int c;
        cin >> c;
        edges.push_back({c,i});
    }
    ranges::sort(edges);
    string s(m,'0');
    int res=0;
    int now=0;
    for(auto [c,i]:edges)
    {
        s[i-1]='1';
        cout << "? " << s << endl;
        int nxt;
        cin >> nxt;
        if(now+c==nxt) res+=c;
        now=nxt;
    }
    cout << "! " << res << endl;
    return 0;
}