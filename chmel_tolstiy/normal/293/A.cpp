#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string d;
        string t;
        cin >> d >> t;
        int a(0), f(0), s(0);
        for (int i = 0; i < 2*n; ++i) {
            a += d[i] == '1' && t[i] == '1';
            f += d[i] == '1' && t[i] != '1';
            s += d[i] != '1' && t[i] == '1';
        }

        a %= 2;

        int first = 0;
        int second = 0;

        if (a) {
            first += 1;
            int d = min(f, s);
            f -= d;
            s -= d;
            if (f) {

            } else {
                second += (s + 1) / 2;
            }
        } else {
            int d = min(f, s);
            f -= d;
            s -= d;
            first += f;
            second += s / 2;
        }

        if (first > second)
            cout << "First" << endl;
        else if (first == second)
            cout << "Draw" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}