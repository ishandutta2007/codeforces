#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 20; i >= 0; --i) {
        if (N & (1 << i)) {
            cout << i +1  <<  ' ';
        }
    }
    return 0;
}