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
        int n,d;
        cin >> n >> d;
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<bool> vis(n,0);
        bool bad=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            vector<int> v;
            for(int j=i;!vis[j];j=(j+d)%n)
            {
                v.push_back(a[j]);
                vis[j]=1;
            }
            int sz=v.size();
            int p=-1;
            for(int j=0;j<sz;j++) if(v[j]==0) p=j;
            if(p==-1) bad=1;
            else
            {
                rotate(v.begin(),v.begin()+p,v.end());
                int l=0;
                while(l<sz)
                {
                    if(v[l]==0)
                    {
                        l++;
                        continue;
                    }
                    int r=l;
                    while(r+1<sz&&v[r+1]==1) r++;
                    res=max(res,r-l+1);
                    l=r+1;
                }
            }
        }
        if(!bad) cout << res << "\n";
        else cout << "-1\n";
    }
    return 0;
}