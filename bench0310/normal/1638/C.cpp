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
        vector<int> p(n+1,0);
        vector<int> q(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            q[p[i]]=i;
        }
        vector<int> m(n+1,0);
        for(int i=1;i<=n;i++) m[i]=max(m[i-1],q[i]);
        int res=0;
        int l=1;
        while(l<=n)
        {
            int r=l;
            int nxt=m[p[l]-1];
            while(r+1<=nxt) nxt=max(nxt,m[p[++r]]);
            res++;
            l=r+1;
        }
        cout << res << "\n";
    }
    return 0;
}