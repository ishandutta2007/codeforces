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
        int k,n,m;
        cin >> k >> n >> m;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> b(m);
        for(int i=0;i<m;i++) cin >> b[i];
        int x=0,y=0;
        vector<int> res;
        while(x<n||y<m)
        {
            if(x<n&&(a[x]==0||a[x]<=k))
            {
                res.push_back(a[x]);
                if(a[x++]==0) k++;
            }
            else if(y<m&&(b[y]==0||b[y]<=k))
            {
                res.push_back(b[y]);
                if(b[y++]==0) k++;
            }
            else
            {
                res={-1};
                break;
            }
        }
        for(int c:res) cout << c << " ";
        cout << "\n";
    }
    return 0;
}