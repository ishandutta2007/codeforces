#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=100000;
    vector<int> v[N+1];
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> p(n+1,1);
        int mn=a[1];
        for(int i=1;i<=n;i++) v[a[i]/p[i]].push_back(i);
        int res=N;
        bool ok=1;
        for(int i=N;i>=0;i--)
        {
            if(ok) res=min(res,i-mn);
            if(i>0)
            {
                for(int j:v[i])
                {
                    p[j]=(a[j]/(a[j]/p[j]))+1;
                    if(p[j]<=k)
                    {
                        v[a[j]/p[j]].push_back(j);
                        mn=min(mn,a[j]/p[j]);
                    }
                    else ok=0;
                }
            }
            v[i].clear();
            v[i].shrink_to_fit();
        }
        cout << res << "\n";
    }
    return 0;
}