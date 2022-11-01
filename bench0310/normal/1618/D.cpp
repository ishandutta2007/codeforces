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
        vector<int> a(n);
        int s=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        ranges::sort(a,greater<>());
        for(int i=0;i<k;i++)
        {
            s-=(a[2*i]+a[2*i+1]);
            s+=(a[i]==a[i+k]);
        }
        cout << s << "\n";
    }
    return 0;
}