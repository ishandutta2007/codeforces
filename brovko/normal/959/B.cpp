#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n, k, m, a[100005], Min[100005];
map <string, int> q;
string s[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        Min[i]=1e9;
        for(int j=0;j<x;j++)
        {
            int y;
            cin >> y;
            y--;
            Min[i]=min(Min[i], a[y]);
            q[s[y]]=i;
        }
    }

    int ans=0;

    for(int i=0;i<m;i++)
    {
        string t;
        cin >> t;
        ans+=Min[q[t]];
    }

    cout << ans;
}