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
        uint32_t x;
        cin >> x;
        int y=(1<<countr_zero(x));
        if(popcount(x)==1) y+=(x>1?1:2);
        cout << y << "\n";
    }
    return 0;
}