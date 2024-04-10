/**********
*         *
*  HELLO  *
*         *
**********/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stdio.h>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

const int mx = 2000000;
int n, m, k, t, u, v, x;
bool b[mx], b1;

int main()
{
    b1 = 0;
    x = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> t;
        b[t-1] = 1;
    }
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        u--;
        v--;
        if (b[x] == 1)
            b1 = 1;
        if (b1 == 0) {
            if (u == x)
                x = v;
            else {
                if (v == x)
                    x = u;
            }
        }
    }
    cout << x+1 << endl;
    return 0;
}