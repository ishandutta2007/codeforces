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
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            v[i]-=x;
        }
        for(int i=0;i<n;i++)
        {
            int y;
            cin >> y;
            v[i]+=y;
        }
        ranges::sort(v,greater<>());
        int r=n-1;
        int res=0;
        for(int l=0;l<n;l++)
        {
            while(r>=0&&v[l]+v[r]<0) r--;
            if(l>=r) break;
            res++;
            r--;
        }
        cout << res << "\n";
    }
    return 0;
}