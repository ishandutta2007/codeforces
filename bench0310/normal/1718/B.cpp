#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=52;
    vector<ll> f(N+1,0);
    f[0]=f[1]=1;
    for(int i=2;i<=N;i++) f[i]=f[i-1]+f[i-2];
    while(t--)
    {
        int k;
        cin >> k;
        vector<ll> c(k);
        ll len=0;
        for(ll &x:c)
        {
            cin >> x;
            len+=x;
        }
        ll s=0;
        int n=0;
        while(s<len) s+=f[n++];
        if(s!=len||k>n)
        {
            cout << "NO\n";
            continue;
        }
        bool ok=0;
        function<void(int,int)> dfs=[&](int p,int o)
        {
            if(p==-1) ok=1;
            array<ll,2> a={-1,-1};
            array<ll,2> b={-1,-1};
            for(int i=0;i<k;i++)
            {
                array<ll,2> e={c[i],i};
                if(e>a)
                {
                    b=a;
                    a=e;
                }
                else if(e>b) b=e;
            }
            if(a[0]>=f[p]&&a[1]!=o)
            {
                c[a[1]]-=f[p];
                dfs(p-1,a[1]);
                c[a[1]]+=f[p];
            }
            if(b[0]>=f[p]&&b[1]!=o)
            {
                c[b[1]]-=f[p];
                dfs(p-1,b[1]);
                c[b[1]]+=f[p];
            }
        };
        dfs(n-1,-1);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}