#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;
    t-=(1ll<<(s.back()-'a'));
    t+=(1ll<<(s[s.size()-2]-'a'));
    s.pop_back();
    s.pop_back();
    vector<ll> c(61,0);
    ll sum=0;
    for(char a:s)
    {
        c[a-'a']++;
        sum+=(1ll<<(a-'a'));
    }
    auto out=[](bool b)
    {
        if(b==1) cout << "Yes\n";
        else cout << "No\n";
        exit(0);
    };
    ll req=sum-t;
    if(abs(t)>abs(sum)) out(0);
    if(req&1) out(0);
    req/=2;
    if(req<0) out(0);
    for(int i=0;i<60;i++)
    {
        if(req&(1ll<<i))
        {
            if(c[i]==0) out(0);
            c[i]--;
        }
        c[i+1]+=(c[i]/2);
    }
    out(1);
    return 0;
}