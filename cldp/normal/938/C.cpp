#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a;
        if (a == 0) {
            cout << "1 1" << endl;
            continue;
        }

        int n, x, m;
        bool flag = false;
        for (int j = 1; j * j <= a; ++j) {
            if (a % j == 0) {
                b = j;
                c = a / b;
                if ((b + c) & 1) continue;
                if (b == c) continue;

                n = (b + c) / 2;
                x = (c - b) / 2;
                m = n / x;
                while (n / m > x) ++m;
                while (n / m < x) --m;
                if (n / m != x) continue;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        
        cout << n << " " << m << endl;

    }
    return 0;
}