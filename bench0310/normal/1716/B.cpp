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
        cout << n << "\n";
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) cout << p[j] << " \n"[j==n];
            if(i<n) swap(p[i],p[i+1]);
        }
    }
    return 0;
}