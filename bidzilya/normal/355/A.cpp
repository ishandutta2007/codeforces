#include <cstdio>
#include <cstring>

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

const int max_int = (1LL << 31) - 1;

int k, d;

int main() {
    cin >> k >> d;
    if (d == 0 && k > 1) {
        cout << "No solution" << endl;
        return 0;
    }
    cout << d;
    for (int i = 0; i < k - 1; ++i)
        cout << 0;
    cout << endl;
    return 0;
}