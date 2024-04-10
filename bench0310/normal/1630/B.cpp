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
        auto go=[&](int n,int k)
        {
            vector<int> a(n+1,0);
            vector<int> c(n+1,0);
            for(int i=1;i<=n;i++)
            {
                cin >> a[i];
                c[a[i]]++;
            }
            vector<int> s(n+1,0);
            for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
            auto sum=[&](int l,int r)->int{return (s[r]-s[l-1]);};
            int req=(n+k)/2;
            array<int,2> opt={1,n};
            int r=1;
            for(int l=1;l<=n;l++)
            {
                while(r<=n&&sum(l,r)<req) r++;
                if(r==n+1) break;
                if(r-l<opt[1]-opt[0]) opt={l,r};
            }
            vector<array<int,2>> v={opt};
            vector<int> p(n+1,0);
            for(int i=1;i<=n;i++)
            {
                if(opt[0]<=a[i]&&a[i]<=opt[1]&&req>0)
                {
                    p[i]=1;
                    req--;
                }
                else p[i]=-1;
            }
            int l=1;
            while(l<=n)
            {
                if((int)v.size()-1==k-1)
                {
                    v.push_back({l,n});
                    break;
                }
                r=l;
                int cnt=0;
                while(cnt<=0) cnt+=p[r++];
                v.push_back({l,r-1});
                l=r;
            }
            return v;
        };
        int n,k;
        cin >> n >> k;
        vector<array<int,2>> v=go(n,k+((n-k)&1));
        if((n-k)&1)
        {
            v.pop_back();
            v.back()[1]=n;
        }
        for(auto [x,y]:v) cout << x << " " << y << "\n";
    }
    return 0;
}