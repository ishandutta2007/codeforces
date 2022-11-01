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
        bool res=1;
        const int inf=(1<<30);
        set<int> s={-inf,inf};
        auto it=s.begin();
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if((*it)>a)
            {
                if(it!=s.begin()) it--;
                res&=((*it)<=a);
            }
            else
            {
                if(next(it)!=s.end()) it++;
                res&=((*it)>=a);
            }
            s.insert(a);
            it=s.find(a);
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}