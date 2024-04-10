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
        vector<int> oa(n,0);
        vector<int> ob(n,0);
        vector<array<int,2>> a(n);
        vector<array<int,2>> b(n);
        for(int i=0;i<n;i++) cin >> oa[i];
        for(int i=0;i<n;i++) cin >> ob[i];
        for(int i=0;i<n;i++)
        {
            a[i]={oa[i],i};
            b[i]={ob[i],i};
        }
        ranges::sort(a);
        ranges::sort(b);
        int l=-1,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            int s=a[m][1];
            int mxa=oa[s],mxb=ob[s];
            int ia=0,ib=0;
            vector<bool> vis(n,0);
            auto add=[&](int x)
            {
                vis[x]=1;
                mxa=max(mxa,oa[x]);
                mxb=max(mxb,ob[x]);
            };
            auto mv_a=[&]()->int
            {
                int mv=0;
                while(ia<n&&mxa>=a[ia][0])
                {
                    add(a[ia][1]);
                    ia++;
                    mv=1;
                }
                return mv;
            };
            auto mv_b=[&]()->int
            {
                int mv=0;
                while(ib<n&&mxb>=b[ib][0])
                {
                    add(b[ib][1]);
                    ib++;
                    mv=1;
                }
                return mv;
            };
            while(1)
            {
                int mv=0;
                mv|=mv_a();
                mv|=mv_b();
                if(mv==0) break;
            }
            bool ok=1;
            for(int i=0;i<n;i++) ok&=(vis[i]==1);
            if(ok) r=m;
            else l=m;
        }
        vector<int> res(n,0);
        for(int i=r;i<n;i++) res[a[i][1]]=1;
        for(int i=0;i<n;i++) cout << res[i];
        cout << "\n";
    }
    return 0;
}