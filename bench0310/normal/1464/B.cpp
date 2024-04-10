#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    ll x,y;
    cin >> x >> y;
    ll q=0;
    for(int i=1;i<=n;i++) q+=(s[i]=='?');
    ll now=0;
    array<ll,2> cnt={0,0};
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?') continue;
        if(s[i]=='0')
        {
            cnt[0]++;
            now+=(cnt[1]*y);
        }
        if(s[i]=='1')
        {
            cnt[1]++;
            now+=(cnt[0]*x);
        }
    }
    vector<array<int,2>> one(n+2,{0,0});
    for(int i=1;i<=n;i++)
    {
        one[i]=one[i-1];
        if(s[i]=='0') one[i][0]++;
        else if(s[i]=='1') one[i][1]++;
    }
    vector<array<int,2>> two(n+2,{0,0});
    for(int i=n;i>=1;i--)
    {
        two[i]=two[i+1];
        if(s[i]=='0') two[i][0]++;
        else if(s[i]=='1') two[i][1]++;
    }
    vector<array<ll,2>> cost(n+2,{0,0});
    for(int i=1;i<=n;i++)
    {
        if(s[i]!='?') continue;
        cost[i][0]=(y*one[i-1][1]+x*two[i+1][1]);
        cost[i][1]=(x*one[i-1][0]+y*two[i+1][0]);
    }
    vector<array<ll,2>> zero(n+2,{0,0}); //dir
    for(int i=1;i<=n;i++) zero[i][0]=zero[i-1][0]+cost[i][0];
    for(int i=n;i>=1;i--) zero[i][1]=zero[i+1][1]+cost[i][0];
    vector<array<ll,2>> ones(n+2,{0,0}); //dir
    for(int i=1;i<=n;i++) ones[i][0]=ones[i-1][0]+cost[i][1];
    for(int i=n;i>=1;i--) ones[i][1]=ones[i+1][1]+cost[i][1];
    ll res=(1ll<<60);
    ll c=0;
    for(int i=0;i<=n;i++)
    {
        c+=(s[i]=='?');
        //01
        res=min(res,zero[i][0]+ones[i+1][1]+(c*(q-c)*x));
        //10
        res=min(res,ones[i][0]+zero[i+1][1]+(c*(q-c)*y));
    }
    cout << res+now << "\n";
    return 0;
}