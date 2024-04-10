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
        vector<vector<int>> v;
        vector<int> c(n+1,0);
        int l=1;
        while(l<=n)
        {
            int r=l;
            while(r+1<=n&&a[r]!=a[r+1]) r++;
            vector<int> b;
            for(int i=l;i<=r;i++) b.push_back(a[i]);
            v.push_back(b);
            c[a[l]]++;
            c[a[r]]++;
            l=r+1;
        }
        int mx=0;
        for(int i=1;i<=n;i++) if(c[i]>=c[mx]) mx=i;
        int opt=0;
        for(vector<int> &b:v)
        {
            int sz=b.size();
            for(int i=0;i<sz-1;i++) opt+=(b[i]!=mx&&b[i+1]!=mx);
        }
        int now=v.size();
        int rm=max(0,c[mx]-(now+1));
        if(opt>=rm) cout << now+rm-1 << "\n";
        else cout << "-1\n";
    }
    return 0;
}