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
        int p=0;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a==n) p=i;
            else v.push_back(a);
        }
        ranges::reverse(v);
        if(p==1||p==n)
        {
            for(int a:v) cout << a << " ";
            cout << n << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}