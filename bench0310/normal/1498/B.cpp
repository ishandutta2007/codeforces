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
        int n,w;
        cin >> n >> w;
        multiset<int> s;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        int res=0;
        while(!s.empty())
        {
            res++;
            int sz=w;
            while(!s.empty())
            {
                auto it=s.upper_bound(sz);
                if(it==s.begin()) break;
                it--;
                sz-=(*it);
                s.erase(it);
            }
        }
        cout << res << "\n";
    }
    return 0;
}