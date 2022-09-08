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

long long a, b, c;
vector<long long> ans;

int power(int a, int b) {
    int res = 1;
    for (int i = 1; i <= b; ++i) {
        res *= a;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    for (int i = 1; i <= 81; ++i) {
        long long x = b * power(i, a) + c;
        long long k = x;
        int sum = 0;
        while (k) {
            sum += k % 10;
            k /= 10;
        }
        if (sum == i && x > 0 && x < 1000000000) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}