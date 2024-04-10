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
        int n,k;
        cin >> n >> k;
        if(k==1||(n%2)==0)
        {
            cout << "YES\n";
            vector<int> v;
            for(int i=1;i<=n*k;i+=2) v.push_back(i);
            for(int i=2;i<=n*k;i+=2) v.push_back(i);
            int idx=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=k;j++) cout << v[idx++] << " \n"[j==k];
            }
        }
        else cout << "NO\n";
    }
    return 0;
}