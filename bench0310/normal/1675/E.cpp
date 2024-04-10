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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s="$"+s;
        int p=0;
        char mx='a';
        while(p+1<=n&&(s[p+1]-'a')<=k) mx=max(mx,s[++p]);
        auto go=[&](char c)
        {
            k--;
            for(char &d:s) if(d==c) d--;
        };
        for(;mx>'a';mx--) go(mx);
        if(p+1<=n) while(k>0) go(s[p+1]);
        cout << s.substr(1,n) << "\n";
    }
    return 0;
}