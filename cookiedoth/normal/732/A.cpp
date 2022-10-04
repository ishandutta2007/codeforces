/************
*           *
*   HELLO   *
*           *
************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, r, k1;
    cin >> k >> r;
    k1 = k;
    int i = 1;
    while (((k1%10) != r)&&((k1%10) != 0)) {
        k1 += k;
        i++;
    }
    cout << i;
    return 0;
}