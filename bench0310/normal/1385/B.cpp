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
        vector<bool> a(n+1,0);
        for(int i=0;i<2*n;i++)
        {
            int x;
            cin >> x;
            if(a[x]==0) cout << x << " ";
            a[x]=1;
        }
        cout << "\n";
    }
    return 0;
}