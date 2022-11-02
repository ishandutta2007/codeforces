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
        for(int i=1;i<=n;i++) cin >> p[i];
        if(n>=2)
        {
            set<int> s;
            for(int i=1;i<=n;i++) s.insert(i);
            for(int i=1;i<=n-2;i++)
            {
                auto it=s.begin();
                if((*it)==p[i]) it++;
                cout << (*it) << " ";
                s.erase(it);
            }
            int x=(*s.begin());
            int y=(*s.rbegin());
            if(p[n-1]==x||p[n]==y) swap(x,y);
            cout << x << " " << y << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}