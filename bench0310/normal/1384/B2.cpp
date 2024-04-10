#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n,k,lim;
        cin >> n >> k >> lim;
        auto tide=[&](int t)->int{return (t<=k?t:2*k-t);};
        auto go=[&](vector<int> d)->bool
        {
            int m=d.size();
            int t=(2*k-(lim-d[0]))%(2*k);
            for(int i=1;i<m;i++)
            {
                if(t>=k)
                {
                    int o=(2*k-(lim-d[i]));
                    t=max(t+1,o);
                    t%=(2*k);
                }
                else
                {
                    t++;
                    if(tide(t)+d[i]>lim) return 0;
                }
            }
            return 1;
        };
        vector<int> d(n+1,0);
        for(int i=1;i<=n;i++) cin >> d[i];
        bool res=[&]()->bool
        {
            int l=1;
            while(l<=n)
            {
                if(d[l]+k<=lim)
                {
                    l++;
                    continue;
                }
                if(d[l]>lim) return 0;
                int r=l;
                while(r+1<=n&&d[r+1]<=lim&&d[r+1]+k>lim) r++;
                vector<int> tmp;
                for(int i=l;i<=r;i++) tmp.push_back(d[i]);
                if(go(tmp)==0) return 0;
                l=r+1;
            }
            return 1;
        }();
        if(res) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}