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
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        if(a>b)
        {
            a=n+1-a;
            b=n+1-b;
        }
        multiset<int> s;
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int one=b-a-1;
        int e=b-1;
        int res=0;
        for(int i=1;i<=min(m,one);i++)
        {
            auto it=s.upper_bound(e-i);
            if(it==s.begin()) continue;
            it--;
            res++;
            s.erase(it);
        }
        cout << res << "\n";
    }
    return 0;
}