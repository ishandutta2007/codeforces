#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        cout << max(a, max(b, c)) << "\n";
    }
}