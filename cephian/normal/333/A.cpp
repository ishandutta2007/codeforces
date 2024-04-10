#include <iostream>

using namespace std;

#define LG long long

int main() {
    LG n;
    cin >> n;
    LG pow = 3;
    while (n % pow == 0)
        pow *= 3;
    cout << (n / pow) + 1;
    return 0;
}