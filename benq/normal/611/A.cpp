#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int x;
    cin >> x;
    string y;
    cin >> y >> y;

    if (y == "week") {
        if (x == 5 || x == 6) {
            cout << 53;
        } else {
            cout << 52;
        }
    } else {
        if (x == 31) {
            cout << 7;
        } else if (x == 30) {
            cout << 11;
        } else {
            cout << 12;
        }
    }
}