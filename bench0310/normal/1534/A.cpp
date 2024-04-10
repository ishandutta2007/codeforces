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
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        set<int> z;
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='R') z.insert((i+j)&1);
                if(s[i][j]=='W') z.insert((i+j+1)&1);
            }
        }
        if(z.empty()) z.insert(0);
        if(z.size()==1)
        {
            cout << "YES\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) cout << "RW"[((*z.begin())+i+j)&1];
                cout << "\n";
            }
        }
        else cout << "NO\n";
    }
    return 0;
}