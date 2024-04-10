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
        bool res=[&]()->bool
        {
            multiset<int> s;
            for(int i=1;i<=n;i++)
            {
                int a;
                cin >> a;
                s.insert(a);
            }
            for(int i=n;i>=1;i--)
            {
                while((*s.rbegin())>i)
                {
                    int a=(*s.rbegin());
                    s.erase(s.find(a));
                    s.insert(a/2);
                }
                if((*s.rbegin())<i) return 0;
                s.erase(s.find(i));
            }
            return 1;
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}