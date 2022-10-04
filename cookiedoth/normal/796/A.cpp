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

const int mx = 500000;
int n, m, k, a[mx];

int main()
{
    int ans = 1000000000;
    cin >> n >> m >> k;
    m--;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 0) {
            if (a[i] <= k) {
                ans = min(ans, abs(i - m) * 10);
            }
        }
    }
    cout << ans << endl;
    return 0;
}