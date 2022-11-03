#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
#include <unordered_map>
using namespace std;

int GetGcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> b(n * n);
    for (int i = 0; i < n * n; ++i) {
        scanf("%d", &b[i]);
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    unordered_map<int, int> rm;
    vector<int> a;
    for (int i = 0; i < n * n; ++i) {
        int x = b[i];

        int& v = rm[x];

        if (v != 0) {
            --v;
        } else {
            for (int j = 0; j < (int) a.size(); ++j) {
                rm[GetGcd(a[j], x)] += 2;
            }
            a.push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}