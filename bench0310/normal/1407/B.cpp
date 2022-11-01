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
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        int g=0;
        for(int i=0;i<n;i++) g=max(g,a[i]);
        for(int i=n;i>=1;i--)
        {
            int idx=0;
            for(int j=0;j<i;j++) if(gcd(g,a[j])>gcd(g,a[idx])) idx=j;
            g=gcd(g,a[idx]);
            cout << a[idx] << " \n"[i==1];
            a.erase(a.begin()+idx);
        }
    }
    return 0;
}