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
        int n,x;
        cin >> n >> x;
        int eq=0;
        int d=0;
        vector<int> v(n,0);
        for(int &a:v)
        {
            cin >> a;
            eq+=(a==x);
            d+=(a-x);
        }
        if(eq==n) cout << "0\n";
        else if(d==0||eq>=1) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}