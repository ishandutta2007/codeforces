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
        for(int i=1;i+3<=n;i+=2) cout << i+1 << " " << i << " ";
        if((n%2)==0) cout << n << " " << n-1 << "\n";
        else cout << n << " " << n-2 << " " << n-1 << "\n";
    }
    return 0;
}