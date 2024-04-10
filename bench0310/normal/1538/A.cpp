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
        vector<int> a(n+1,0);
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            p[a[i]]=i;
        }
        int x=p[1];
        int y=p[n];
        if(x>y) swap(x,y);
        int res=min({y,n-x+1,x+n-y+1});
        cout << res << "\n";
    }
    return 0;
}