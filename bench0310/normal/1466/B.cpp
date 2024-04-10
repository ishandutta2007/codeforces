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
        vector<int> x(n,0);
        for(int i=0;i<n;i++) cin >> x[i];
        sort(x.begin(),x.end(),greater<int>());
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(i==0||x[i-1]>x[i]+1) x[i]++;
            res+=(i==0||x[i-1]!=x[i]);
        }
        cout << res << "\n";
    }
    return 0;
}