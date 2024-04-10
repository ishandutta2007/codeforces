#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto opt=[](int a)->int{return 2*((a+1)/2)+((a&1)==0);};
    if((n%2)==0) cout << opt(n/2)*opt(n/2) << "\n";
    else cout << 2*opt(n/2)*opt((n+1)/2) << "\n";
    return 0;
}