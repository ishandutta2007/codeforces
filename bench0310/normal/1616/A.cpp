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
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            m[abs(a)]++;
        }
        int res=0;
        for(auto [a,c]:m) res+=min(1+(a!=0),c);
        cout << res << "\n";
    }
    return 0;
}