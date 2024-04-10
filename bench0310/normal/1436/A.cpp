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
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            m-=a;
        }
        if(m==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}