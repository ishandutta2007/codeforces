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
        vector<string> s(2);
        cin >> s[0] >> s[1];
        vector<int> v(n,2);
        for(int i=0;i<n;i++) if(s[0][i]==s[1][i]) v[i]=(s[0][i]-'0');
        vector<bool> vis(n,0);
        int res=0;
        int l=0;
        while(l<n)
        {
            if(v[l]==2)
            {
                res+=2;
                l++;
                continue;
            }
            int r=l;
            while(r+1<n&&v[r+1]!=2) r++;
            for(int i=l;i<=r;i++)
            {
                if(v[i]==1) continue;
                int x=1;
                if(i-1>=l&&v[i-1]==1&&vis[i-1]==0)
                {
                    x++;
                    vis[i-1]=1;
                }
                else if(i+1<=r&&v[i+1]==1&&vis[i+1]==0)
                {
                    x++;
                    vis[i+1]=1;
                }
                res+=x;
            }
            l=r+1;
        }
        cout << res << "\n";
    }
    return 0;
}