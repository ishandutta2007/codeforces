#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    vector<ll> opt(N+1,0);
    opt[0]=1;
    ll sum=1;
    const ll lim=(1ll<<60);
    for(int i=1;i<=N;i++)
    {
        opt[i]=sum;
        sum=min(lim,sum+opt[i]);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        if(opt[n]<k)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> res(n+1,0);
        function<void(int)> go=[&](int i)
        {
            if(i==n+1) return;
            for(int c=1;c<=n-i+1;c++)
            {
                if(opt[n-i-c+1]>=k)
                {
                    for(int j=i;j<i+c;j++) res[j]=(i+c-1-(j-i));
                    go(i+c);
                    break;
                }
                else k-=opt[n-i-c+1];
            }
        };
        go(1);
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}