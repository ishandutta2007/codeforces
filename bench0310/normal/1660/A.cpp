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
        int a,b;
        cin >> a >> b;
        if(a==0) cout << "1\n";
        else cout << min(2*(a/2),((a&1)?a:a-1))+2*b+2 << "\n";
    }
    return 0;
}