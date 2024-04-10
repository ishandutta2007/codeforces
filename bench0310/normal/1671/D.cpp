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
        int n,x;
        cin >> n >> x;
        int a=200000,b=0;
        ll res=0;
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> c[i];
            a=min(a,c[i]);
            b=max(b,c[i]);
            if(i>=2) res+=abs(c[i]-c[i-1]);
        }
        if(1<a)
        {
            int mn=min(abs(c[1]-1),abs(c[n]-1));
            for(int i=2;i<n;i++) mn=min(mn,2*abs(c[i]-1));
            res+=mn;
        }
        if(b<x)
        {
            int mn=min(abs(c[1]-x),abs(c[n]-x));
            for(int i=2;i<n;i++) mn=min(mn,2*abs(c[i]-x));
            res+=mn;
        }
        cout << res << "\n";
    }
    return 0;
}