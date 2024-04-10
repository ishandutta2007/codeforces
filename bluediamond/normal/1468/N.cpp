/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

int c1, c2, c3;

int a1, a2, a3, a4, a5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> c1 >> c2 >> c3;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        int aux;
        aux = min(c1, a1);
        c1 -= aux; a1 -= aux;
        aux = min(c2, a2);
        c2 -= aux; a2 -= aux;
        aux = min(c1, a4);
        c1 -= aux; a4 -= aux;
        aux = min(c2, a5);
        c2 -= aux; a5 -= aux;
        aux = min(c3, a4);
        c3 -= aux; a4 -= aux;
        aux = min(c3, a5);
        c3 -= aux; a5 -= aux;
        aux = min(c3, a3);
        c3 -= aux; a3 -= aux;
        if(a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}