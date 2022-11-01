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
        string a,b;
        cin >> a >> b;
        int n=a.size();
        int m=b.size();
        int mx=0;
        for(int l=0;l<n;l++)
        {
            for(int r=l;r<n;r++)
            {
                string s=a.substr(l,r-l+1);
                for(int j=0;j<m;j++) if(s==b.substr(j,r-l+1)) mx=max(mx,r-l+1);
            }
        }
        cout << n+m-2*mx << "\n";
    }
    return 0;
}