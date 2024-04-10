#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r){return uniform_int_distribution<int>(l,r)(gen);};
    array<ll,2> mod={1000000007,rng(1000000008,2000000000)};
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        string s;
        cin >> n >> k >> s;
        for(int i=0;i<n;i++) s[i]=('0'+'1'-s[i]);
        array<ll,2> now={0,0};
        for(int i=0;i<k-1;i++) for(int j=0;j<2;j++) now[j]=(2*now[j]+(s[i]-'0'))%mod[j];
        set<array<ll,2>> bad;
        array<ll,2> p={1,1};
        for(int i=0;i<k-1;i++) for(int j=0;j<2;j++) p[j]=(2*p[j])%mod[j];
        for(int i=k-1;i<n;i++)
        {
            for(int j=0;j<2;j++) now[j]=(2*now[j]+(s[i]-'0'))%mod[j];
            bad.insert(now);
            for(int j=0;j<2;j++) now[j]=(now[j]-p[j]*(s[i-k+1]-'0')+mod[j])%mod[j];
        }
        int lim=n-k+1;
        if(k<=20) lim=min(lim,(1<<k)-1);
        string res;
        for(int i=0;i<=lim;i++)
        {
            if(bad.find({i,i})==bad.end())
            {
                int x=i;
                for(int j=0;j<k;j++)
                {
                    res+=char('0'+x%2);
                    x/=2;
                }
                reverse(res.begin(),res.end());
                break;
            }
        }
        if(!res.empty()) cout << "YES\n" << res << "\n";
        else cout << "NO\n";
    }
    return 0;
}