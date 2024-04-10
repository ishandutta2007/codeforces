#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1, inf = 1111111111;

int n;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        v.push_back(1);
        while (v.size() > 1 && v[v.size() - 1] == v[v.size() - 2]) {
            v.pop_back();
            ++v[v.size() - 1];
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        printf("%d ", v[i]);
    }
    return 0;
}