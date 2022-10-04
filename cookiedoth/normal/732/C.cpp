/************
*           *
*   HELLO   *
*           *
************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long m[3];
    cin >> m[0] >> m[1] >> m[2];
    sort(m, m+3);
    if (m[2] > m[1]) cout << (m[2]-1)*2 - m[1] - m[0];
    if ((m[2] == m[1])&&(m[1] > m[0])) cout << (m[2] - 1) - m[0];
    if ((m[2] == m[1])&&(m[1] == m[0])) cout << 0;
    return 0;
}