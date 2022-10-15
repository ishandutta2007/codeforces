#include <iostream>
#include <map>
using namespace std;

bool f[10];

int main()
{
    int n, c(0);
    char ch;
    cin >> n;
    map < char, int > m {{'R', 0}, {'U', 1}, {'D', 2}, {'L', 3}};
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        if (f[3 - m[ch]]) {
            ++c;
            f[0] = f[1] = f[2] = f[3] = false;
        }
        f[m[ch]] = true;
    }
    cout << c + 1;
    return 0;
}