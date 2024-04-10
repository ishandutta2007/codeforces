#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,26>> s(n);
    for(int i=0;i<n;i++)
    {
        string t;
        cin >> t;
        array<int,26> c;
        c.fill(0);
        for(char a:t) c[a-'a']++;
        s[i]=c;
    }
    const int mod=998244353;
    auto add=[&](int a,int b)->int{return a+b-(a+b>=mod?mod:0);};
    auto sub=[&](int a,int b)->int{return a-b+(a-b<0?mod:0);};
    auto mul=[&](int a,int b)->int{return (ll(a)*b)%mod;};
    vector<int> f((1<<n),0);
    for(int m=1;m<(1<<n);m++)
    {
        array<int,26> c;
        c.fill(20000);
        for(int i=0;i<n;i++)
        {
            if((m&(1<<i))==0) continue;
            for(int j=0;j<26;j++) c[j]=min(c[j],s[i][j]);
        }
        f[m]=1;
        for(int j=0;j<26;j++) f[m]=mul(f[m],c[j]+1);
    }
    for(int m=0;m<(1<<n);m++) if(popcount(uint32_t(m))&1) f[m]=sub(0,f[m]);
    for(int i=0;i<n;i++) for(int m=0;m<(1<<n);m++) if(m&(1<<i)) f[m]=add(f[m],f[m^(1<<i)]);
    ll res=0;
    for(int m=1;m<(1<<n);m++)
    {
        int mu=sub(0,f[m]);
        int sum=0;
        for(int i=0;i<n;i++) if(m&(1<<i)) sum+=(i+1);
        ll x=ll(mu)*sum*popcount(uint32_t(m));
        res^=x;
    }
    cout << res << "\n";
    return 0;
}