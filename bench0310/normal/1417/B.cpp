#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,s;
        cin >> n >> s;
        map<int,vector<int>> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            m[a].push_back(i);
        }
        vector<int> res(n+1,0);
        for(auto &[a,v]:m)
        {
            if(a>s-a) break;
            if(a<s-a) for(int x:v) res[x]=1;
            else for(int i=0;i<(int)v.size()/2;i++) res[v[i]]=1;
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}