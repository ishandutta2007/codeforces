#include "bits/stdc++.h"

using namespace std;

int main() {
    int a;
    cin >> a;
    a %= 9;
    if (!a) a = 9;
    cout << a << endl;
    return 0;
}