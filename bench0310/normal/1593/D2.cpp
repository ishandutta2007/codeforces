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
        vector<int> opt;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int b=abs(a[i]-a[j]);
                for(int d=1;d*d<=b;d++)
                {
                    if(b%d) continue;
                    opt.push_back(d);
                    if(d*d!=b) opt.push_back(b/d);
                }
            }
        }
        int res=1;
        const int inf=(1<<30);
        opt.push_back(inf);
        for(int b:opt)
        {
            vector<int> v;
            for(int i=1;i<=n;i++) v.push_back(((a[i]%b)+b)%b);
            sort(v.begin(),v.end());
            int l=0;
            while(l<n)
            {
                int r=l;
                while(r+1<n&&v[r+1]==v[l]) r++;
                if(r-l+1>=(n+1)/2) res=max(res,b);
                l=r+1;
            }
        }
        if(res==inf) res=-1;
        cout << res << "\n";
    }
    return 0;
}