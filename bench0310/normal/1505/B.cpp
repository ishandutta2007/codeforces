#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int d=0;
    while(n)
    {
        d+=(n%10);
        n/=10;
    }
    d%=9;
    if(d==0) d=9;
    cout << d << "\n";
    return 0;
}