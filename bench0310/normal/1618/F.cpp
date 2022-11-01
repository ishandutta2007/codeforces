#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,y;
    cin >> x >> y;
    auto to_binary=[&](ll a)->string
    {
        string s;
        while(a)
        {
            s+=char('0'+(a%2));
            a/=2;
        }
        ranges::reverse(s);
        return s;
    };
    auto go=[&](string s,string t)->bool
    {
        int n=s.size();
        int m=t.size();
        for(int o=0;o<2;o++)
        {
            for(int i=0;i+n-1<m;i++)
            {
                bool ok=(s==t.substr(i,n));
                for(int j=0;j<i;j++) ok&=(t[j]=='1');
                for(int j=i+n;j<m;j++) ok&=(t[j]=='1');
                if(ok) return 1;
            }
            ranges::reverse(s);
        }
        return 0;
    };
    string s=to_binary(x);
    string t=to_binary(y);
    bool res=(s==t);
    res|=go(s+"1",t);
    while(s.back()=='0') s.pop_back();
    res|=go(s,t);
    if(res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}