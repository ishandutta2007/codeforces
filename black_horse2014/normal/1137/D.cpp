#include <bits/stdc++.h>
using namespace std;

int input() {
    int x; cin >> x;
    int ret = x;
    while (x--) {
        string temp;
        cin >> temp;
    }
    return ret;
}

int main() {
    while (1) {
        cout << "next 0 1" << endl;
        input();
        cout << "next 1" << endl;
        if (input() == 2) break;
    }
    while (1) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        int ret = input();
        if (ret == 1) break;
    }
    cout << "done" << endl;
    return 0;
}