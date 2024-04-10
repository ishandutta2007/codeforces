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
        vector<int> q(n+1,0);
        vector<int> p(n+1,0);
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        for(int i=1;i<=n;i++)
        {
            cin >> q[i];
            if(q[i]>q[i-1])
            {
                p[i]=q[i];
                s.erase(q[i]);
            }
        }
        auto it=s.begin();
        for(int i=1;i<=n;i++) cout << (p[i]!=0?p[i]:(*(it++))) << " \n"[i==n];
        for(int i=1;i<=n;i++)
        {
            if(p[i]!=0) cout << p[i] << " \n"[i==n];
            else
            {
                it=s.upper_bound(q[i]);
                it--;
                cout << (*it) << " \n"[i==n];
                s.erase(it);
            }
        }
    }
    return 0;
}