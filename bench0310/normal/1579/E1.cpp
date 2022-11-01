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
        vector<int> h(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            h[p[i]]=i;
        }
        int lim=n;
        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(h[i]>lim) continue;
            v[h[i]]=1;
            lim=h[i]-1;
        }
        deque<int> d;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0) d.push_back(p[i]);
            else d.push_front(p[i]);
        }
        for(int i=0;i<n;i++) cout << d[i] << " \n"[i==n-1];
    }
    return 0;
}