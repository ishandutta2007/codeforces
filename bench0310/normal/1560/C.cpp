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
        int k;
        cin >> k;
        int n=1;
        while(n*n<k) n++;
        k-=((n-1)*(n-1));
        if(k<=n) cout << k << " " << n << "\n";
        else cout << n << " " << n-(k-n) << "\n";
    }
    return 0;
}