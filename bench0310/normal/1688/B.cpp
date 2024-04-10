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
        int e=0,m=30;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            e+=((a%2)==0);
            int c=countr_zero(uint32_t(a));
            m=min(m,c);
        }
        if(e<n) cout << e << "\n";
        else cout << m+e-1 << "\n";
    }
    return 0;
}