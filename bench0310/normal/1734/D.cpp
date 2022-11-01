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
        vector<int> a(n+2,0);
        auto go=[&](int k)->bool
        {
            vector<array<ll,2>> v;
            int p=k-1;
            while(p>=1)
            {
                int l=p;
                ll mn=0;
                ll sum=0;
                while(l>=1&&sum<=0)
                {
                    sum+=a[l];
                    mn=min(mn,sum);
                    l--;
                }
                if(sum>0) v.push_back({sum,mn});
                p=l;
            }
            int x=0;
            int len=v.size();
            ll h=a[k];
            for(int i=k+1;i<=n;i++)
            {
                while(x<len&&h+v[x][1]>=0) h+=v[x++][0];
                h+=a[i];
                if(h<0) return 0;
            }
            return 1;
        };
        int k;
        cin >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        bool res=go(k);
        ranges::reverse(a);
        res|=go(n-k+1);
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}