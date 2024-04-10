#include <iostream>
using namespace std;


int main() {
    int A, B;
    char c;
    cin >> A >> c >> B;

    int ans = 0;
    while (true) {
        if (A / 10 == B % 10 && B / 10 == A % 10) break;
        ++ans;
        ++B;
        if (B == 60) {
            ++A;
            B = 0;
        }
        if (A == 24) A = 0;
    }
    cout << ans << endl;
    return 0;
}