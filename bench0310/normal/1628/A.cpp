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
        vector<bool> v(n+1,0);
        vector<int> s(n+1,0);
        int mex=0;
        for(int i=n;i>=0;i--)
        {
            v[a[i]]=1;
            while(v[mex]) mex++;
            s[i]=mex;
        }
        v.assign(n+1,0);
        vector<int> b;
        int l=1;
        while(l<=n)
        {
            int tmp=s[l];
            b.push_back(tmp);
            if(tmp==0)
            {
                l++;
                continue;
            }
            int r=l;
            int now=0;
            auto add=[&](int x)
            {
                v[x]=1;
                while(v[now]) now++;
            };
            add(a[l]);
            while(now!=tmp)
            {
                r++;
                add(a[r]);
            }
            for(int i=l;i<=r;i++) v[a[i]]=0;
            l=r+1;
        }
        cout << b.size() << "\n";
        for(int x:b) cout << x << " ";
        cout << "\n";
    }
    return 0;
}