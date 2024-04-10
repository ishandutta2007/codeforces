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
        int a;
        cin >> a;
        int x=((a%10)-1);
        int d=to_string(a).size();
        cout << 10*x+d*(d+1)/2 << "\n";
    }
    return 0;
}