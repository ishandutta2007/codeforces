#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>
 
using namespace std;

typedef long long ll;

const int max_n = 5e3 + 10;

int a[max_n];
int b[max_n];
int n, m;
set<int> is_bad_prime;
int g[max_n];

int f(int x) {
    int result = 0;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            int d = 0;
            while (x % i == 0) {
                x /= i;
                ++d;
            }
            if (is_bad_prime.find(i) != is_bad_prime.end()) {
                result -= d;
            } else {
                result += d;
            }
        }
    if (x > 1) {
        if (is_bad_prime.find(x) != is_bad_prime.end()) {
            --result;
        } else {
            ++result;
        }
    }
    return result;
}

int gcd(int a, int b) {
    while (a > 0 && b > 0)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main() {
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        is_bad_prime.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d", b + i);
            is_bad_prime.insert(b[i]);
        }
        g[0] = a[0];
        for (int i = 1; i < n; ++i)
            g[i] = gcd(g[i - 1], a[i]);
        int all_answer = 0;
        for (int i = 0; i < n; ++i) 
            all_answer += f(a[i]);
        int answer = all_answer;
        int d = 1;
        for (int i = n - 1; i >= 0; --i) {
            g[i] /= d;
            int res = f(g[i]);
            if (res < 0) {
                answer -= res * (i + 1);
                d *= g[i];
            }
        }
        printf("%d\n", answer);
    }
    
    
    return 0;
}