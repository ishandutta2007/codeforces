/*****************
*                *
*  savkinsd2089  *
*                *
*****************/

#include <bits/stdc++.h>

using namespace std;

int n, ans;

int nim(int x) {
    if (x <= 0) return 0;
    if (x <= 2) return 1;
    if (x <= 5) return 2;
    if (x <= 9) return 3;
    if (x <= 14) return 4;
    if (x <= 20) return 5;
    if (x <= 27) return 6;
    if (x <= 35) return 7;
    if (x <= 44) return 8;
    if (x <= 54) return 9;
    return 10;
}

int main()
{
    int temp;
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        ans = ans ^ nim(temp);
    }
    if (ans == 0) cout << "YES";
    else cout << "NO";
    return 0;
}