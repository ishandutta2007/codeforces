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
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll res=0;
        const ll mod=998244353;
        if(n<=8)
        {
            for(int i=0;i<(1<<n);i++)
            {
                vector<int> c,p;
                ll sum=0;
                for(int j=0;j<n;j++)
                {
                    if(i&(1<<j))
                    {
                        sum-=a[j+1];
                        c.push_back(j);
                    }
                    else
                    {
                        sum+=a[j+1];
                        p.push_back(j);
                    }
                }
                bool ok=(sum>0);
                for(int j=1;j<(int)c.size()-1;j++) ok&=(c[j]-c[j-1]<=c[j+1]-c[j]);
                for(int j=1;j<(int)p.size()-1;j++) ok&=(p[j]-p[j-1]>=p[j+1]-p[j]);
                res+=ok;
            }
        }
        else
        {
            vector<ll> s(n+1,0);
            for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
            vector<ll> alts(n+3,0);
            for(int i=n;i>=1;i--) alts[i]=a[i]+alts[i+2];
            auto sum=[&](int l,int r)->ll{return (s[r]-s[l-1]);};
            auto altsum=[&](int l,int r)->ll
            {
                if((l&1)==(r&1)) return alts[l]-alts[r+2];
                else return alts[l]-alts[r+1];
            };
            ll lim=(s[n]-1)/2;
            for(int i=0;i<=n;i++)
            {
                for(int x=0;x<2;x++)
                {
                    for(int y=0;y<2;y++)
                    {
                        if(x==1&&i<=2) continue;
                        ll now=s[i]-(x==1)*a[1]+(y==1)*a[n];
                        if(now>lim) continue;
                        int l=0;
                        int r=(n-i)/2+1;
                        while(l<r-1)
                        {
                            int m=(l+r)/2;
                            if(now+altsum(i+2,i+2*m)<=lim) l=m;
                            else r=m;
                        }
                        while(y==1&&i+2*l>=n-2) l--;
    //                    cout << "i=" << i << ", " << "x=" << x << ", " << "y=" << y << ": " << l << endl;
                        res+=(l+1);
                    }
                }
            }
            for(int i=1;i<n-1;i++) if(sum(i+1,n)<=lim) res++;
        }
        cout << (res%mod) << "\n";
    }
    return 0;
}