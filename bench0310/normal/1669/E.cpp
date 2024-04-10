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
        map<string,int> m;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin >> s;
            m[s]++;
        }
        ll res=0;
        for(auto [x,a]:m)
        {
            for(auto [y,b]:m)
            {
                if(x>=y) continue;
                int c=0;
                for(int i=0;i<2;i++) c+=(x[i]!=y[i]);
                if(c==1) res+=(ll(a)*b);
            }
        }
        cout << res << "\n";
    }
    return 0;
}