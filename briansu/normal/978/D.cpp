#include <cmath>
#include <iostream>
using namespace std;

const int MAXn = 1e5 + 5;

int d[MAXn], mod[MAXn]; // original and modified

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int ans = 12345678;
    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++) {
            int count = (int)(x != 0) + (int)(y != 0); 
            mod[1] = d[1] + x;
            mod[2] = d[2] + y;
            int target = mod[2] - mod[1];
            for (int i = 3; i <= n; i++) {
                int current = d[i] - mod[i - 1];
                if (abs(current - target) > 1) {
                    count = -1;
                    break;
                }
                else
                    mod[i] = d[i] + (target - current);
                if (target != current)
                    count += 1;
            }
            if (count != -1)
                ans = min(ans, count);
        }
    if (ans > n)
        cout << -1 << endl;
    else 
        cout << ans << endl;
}