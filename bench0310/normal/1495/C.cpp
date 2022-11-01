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
        vector<string> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> v;
        if((n%3)==1) for(int i=0;i<n;i+=3) v.push_back(i);
        else for(int i=1;i<n;i+=3) v.push_back(i);
        for(int r:v) for(int j=0;j<m;j++) a[r][j]='X';
        for(int x=0;x<(int)v.size()-1;x++)
        {
            int r=v[x]+1;
            [&]()
            {
                for(int j=0;j<m;j++)
                {
                    if(a[r][j]=='X')
                    {
                        a[r+1][j]='X';
                        return;
                    }
                    if(a[r+1][j]=='X')
                    {
                        a[r][j]='X';
                        return;
                    }
                }
                a[r][0]=a[r+1][0]='X';
            }();
        }
        for(int i=0;i<n;i++) cout << a[i] << "\n";
    }
    return 0;
}