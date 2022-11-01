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
        multiset<int> a,b;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            a.insert(x);
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            b.insert(x);
        }
        auto f=[&](int x)->int{return int(to_string(x).size());};
        int res=0;
        while(!a.empty())
        {
            int x=(*a.rbegin());
            int y=(*b.rbegin());
            if(x==y)
            {
                a.erase(a.find(x));
                b.erase(b.find(y));
            }
            else
            {
                res++;
                if(x>y)
                {
                    a.erase(a.find(x));
                    a.insert(f(x));
                }
                else
                {
                    b.erase(b.find(y));
                    b.insert(f(y));
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}