#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s;
    int n=s.size();
    int l=0;
    int r=n-1;
    while(l<n && s[l]!='[')
        l++;
    while(r>=0 && s[r]!=']')
        r--;

    while(l<n && s[l]!=':')
        l++;
    while(r>=0 && s[r]!=':')
        r--;

    if(r<=l)
    {
        cout << -1;
        return 0;
    }

    int ans=4;
    for(int i=l;i<=r;i++)
        if(s[i]=='|')
            ans++;
    cout << ans;
}