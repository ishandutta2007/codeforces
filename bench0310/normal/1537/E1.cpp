#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n>k)
    {
        n=k;
        s=s.substr(0,n);
    }
    auto go=[&](string t)->string
    {
        string r;
        while((int)r.size()<k) r+=t;
        return r.substr(0,k);
    };
    string res=go(s);
    for(int i=1;i<=n;i++) res=min(res,go(s.substr(0,i)));
    cout << res << "\n";
    return 0;
}