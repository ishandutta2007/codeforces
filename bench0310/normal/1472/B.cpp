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
        int sum=0;
        array<int,3> c={0,0,0};
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            sum+=a;
            c[a]++;
        }
        bool res=[&]()->bool
        {
            if(sum&1) return 0;
            int x=min((sum/2)/2,c[2]);
            return (sum/2-2*x<=c[1]);
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}