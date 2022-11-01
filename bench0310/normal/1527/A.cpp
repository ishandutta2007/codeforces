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
        int x=0;
        for(int i=0;i<30;i++) if(n&(1<<i)) x=i;
        cout << (1<<x)-1 << "\n";
    }
    return 0;
}