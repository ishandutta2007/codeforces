#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <array>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

const int mx = 500;
int time[mx][5], n, solve[5], pow2[7], change[5];

int cost(int solved, int all) {
    for (int i = 1; i < 6; ++i) {
        if (pow2[i] * solved > all)
            return i * 500;
    }
    return 3000;
}

bool check(int k) {
    int b0 = 0, b1 = 0;
    for (int i = 0; i < 5; ++i) {
        if ((change[i] == 1) && (time[0][i] == -1))
            return 0;
        int solved, n1;
        solved = solve[i] + change[i] * k;
        n1 = n + k;
        if (time[0][i] > -1) {
            b0 += cost(solved, n1);
            b0 -= (cost(solved, n1) * time[0][i]) / 250;
        }
        if (time[1][i] > -1) {
            b1 += cost(solved, n1);
            b1 -= (cost(solved, n1) * time[1][i]) / 250;
        }
    }
    if (b0 > b1)
        return 1;
    else
        return 0;
}

int main()
{
    pow2[0] = 1;
    for (int i = 1; i <= 6; ++i) {
        pow2[i] = pow2[i-1] * 2;
    }
    cin >> n;
    for (int i = 0; i < 5; ++i) {
        solve[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> time[i][j];
            if (time[i][j] > -1)
                solve[j]++;
        }
    }
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 32; ++j) {
            int e = j;
            for (int a = 0; a < 5; ++a) {
                change[a] = e % 2;
                e = e / 2;
            }
            if (check(i)) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}