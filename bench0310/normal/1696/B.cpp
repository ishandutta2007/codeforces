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
        vector<int> z={0};
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i]==0) z.push_back(i);
        }
        z.push_back(n+1);
        int sz=z.size();
        int c=0;
        for(int i=0;i+1<sz;i++) c+=(z[i]+1<z[i+1]);
        cout << min(c,2) << "\n";
    }
    return 0;
}