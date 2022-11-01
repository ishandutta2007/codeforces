#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        string s,t;
        cin >> s >> t;
        ranges::sort(s);
        ranges::sort(t);
        int p=0,c=0;
        int x=0,y=0;
        while(x<n&&y<m)
        {
            int e=(s[x]>t[y]);
            if(e==p&&c==k) e^=1;
            if(e==p) c++;
            else
            {
                p=e;
                c=1;
            }
            if(e==0) cout << s[x++];
            else cout << t[y++];
        }
        cout << "\n";
    }
    return 0;
}