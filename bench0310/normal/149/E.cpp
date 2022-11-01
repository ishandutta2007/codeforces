#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    const ll mod=uniform_int_distribution<int>(100000000,2000000000)(gen);
    const ll p=31;
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    vector<ll> z(n+1,0);
    for(int i=1;i<=n;i++) z[i]=(p*z[i-1]+(s[i]-'A'))%mod;
    vector<ll> pw(n+1,1);
    for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*p)%mod;
    auto h=[&](int l,int r)->ll{return (((z[r]-z[l-1]*pw[r-(l-1)])%mod)+mod)%mod;};
    int q;
    cin >> q;
    int res=0;
    while(q--)
    {
        string t;
        cin >> t;
        int m=t.size();
        t="$"+t;
        vector<int> one(m+1,n+1);
        int idx=1;
        ll x=0;
        for(int i=1;i<=m;i++)
        {
            x=(p*x+(t[i]-'A'))%mod;
            while(idx+i-1<=n&&h(idx,idx+i-1)!=x) idx++;
            if(h(idx,idx+i-1)==x) one[i]=idx;
            else break;
        }
        vector<int> two(m+1,0);
        idx=n;
        x=0;
        for(int i=m;i>=1;i--)
        {
            x=(x+pw[m-i]*(t[i]-'A'))%mod;
            while(idx-(m-i+1)+1>=1&&h(idx-(m-i+1)+1,idx)!=x) idx--;
            if(h(idx-(m-i+1)+1,idx)==x) two[i]=idx;
            else break;
        }
        bool ok=0;
        for(int i=1;i<=m-1;i++) ok|=(one[i]+i-1<two[i+1]-(m-i)+1);
        res+=ok;
    }
    cout << res << "\n";
    return 0;
}