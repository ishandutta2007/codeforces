#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long m, r;
    cin >> m >> r;
    
    double ans = 0;
    
    for(int i = 1; i < m; i++)
        ans += 2 * r * 2 * i * (m - i);
        
    ans += 2 * r * m;
    ans += (r + r * (sqrt(2) - 1)) * (m - 1) * 2;
    ans += 2 * r * (sqrt(2) - 1) * (m * m - m - (m - 1) * 2);
    
    ans /= (m * m);
    
    cout << setprecision(20) << ans;
}