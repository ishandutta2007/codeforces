#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll tc;
    cin >> tc;
    // tc = 1;
    while (tc--)
    {
        // -------   check for n==1   -------------
        ll n;
        cin >> n;
        ll n1 = n / 2, n2 = n / 4;
        ll sqr1 = sqrt(n1), sqr2 = sqrt(n2);
        // cout << sqr1 << " " << sqr2 << " ";
 
        if ((n % 2 == 0 && sqr1 * sqr1 == n1) || (n % 4 == 0 && sqr2 * sqr2 == n2))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
 
        cout << endl;
    }
    return 0;
}