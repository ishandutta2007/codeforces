#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    array<int,3> a={6,10,14};
    array<int,3> b={6,10,15};
    while(t--)
    {
        int n;
        cin >> n;
        if(n<=30) cout << "NO\n";
        else
        {
            cout << "YES\n";
            array<int,3> x=((n==36||n==40||n==44)?b:a);
            cout << x[0] << " " << x[1] << " " << x[2] << " " << n-x[0]-x[1]-x[2] << "\n";
        }
    }
    return 0;
}