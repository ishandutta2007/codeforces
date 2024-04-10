#include <cstdio>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 2e3;

int n;
int a[max_n], b[max_n], c[max_n];
int cn[2], k;

void do_even(int i) {
    ++cn[0];
    ++cn[1];
    for (int j = 0; j < 2 * n; ++j)
        if (a[j] == i) {
            c[j] = (b[i] % 2);
            --b[i];
        }
}

void do_odd(int i) {
    if (b[i] > 1) {
        ++cn[0];
        ++cn[1];
    } else {
        ++cn[k];
    }
    int t;
    for (int j = 0; j < 2 * n; ++j)
        if (a[j] == i) {
            t = j;
            c[j] = (b[i] % 2);
            --b[i];
        }
    c[t] = k;
    k = (k + 1) % 2;
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        ++b[a[i]];
    }
    cn[0] = cn[1] = k = 0;
    for (int i = 0; i < max_n; ++i) 
        if (b[i] > 1) {
            if (b[i] % 2 == 1)
                do_odd(i);
            else
                do_even(i);
        }
    for (int i = 0; i < max_n; ++i)
        if (b[i] == 1)
            do_odd(i);
    cout << cn[0] * cn[1] << endl;
    for (int i = 0; i < 2 * n; ++i)
        cout << (c[i] + 1) << " ";
    cout << endl;
    return 0;
}