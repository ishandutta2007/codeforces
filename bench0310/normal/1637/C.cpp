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
        ll sum=0;
        int odd=0;
        bool two=0;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(2<=i&&i<=n-1)
            {
                sum+=a[i];
                two|=(a[i]>=2);
                odd+=(a[i]&1);
            }
        }
        if((n>=4&&two)||(n==3&&((a[2]%2)==0))) cout << odd+(sum-odd)/2 << "\n";
        else cout << "-1\n";
    }
    return 0;
}