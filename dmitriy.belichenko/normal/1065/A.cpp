#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <random>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s , a , b , c;
        cin >> s >> a >> b >> c;
        cout << (s / (c * a) *  b + s / c) << "\n";
    }
}