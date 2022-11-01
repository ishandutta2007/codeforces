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
        string s;
        cin >> s;
        s="$"+s;
        int a=0,b=0;
        map<array<int,2>,int> best;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='D') a++;
            else b++;
            int r=i;
            if(min(a,b)>0)
            {
                int g=gcd(a,b);
                r=(++best[{a/g,b/g}]);
            }
            cout << r << " \n"[i==n];
        }
    }
    return 0;
}