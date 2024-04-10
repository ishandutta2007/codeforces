#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int o=0;o<n;o++) cin >> s[o];
    ll res=n;
    vector<int> now(n,1);
    for(int i=m-2;i>=0;i--)
    {
        vector<int> nxt(n,1);
        for(int o=1;o<n-1;o++)
        {
            char c=s[o][i];
            if(s[o-1][i+1]!=c||s[o][i+1]!=c||s[o+1][i+1]!=c) continue;
            nxt[o]=min(min(now[o-1],now[o]),now[o+1]);
            int x=i+2*nxt[o]-1+1;
            if(x<m&&s[o][x]==c) nxt[o]++;
        }
        now=nxt;
        for(int o=0;o<n;o++) res+=now[o];
    }
    cout << res << "\n";
    return 0;
}