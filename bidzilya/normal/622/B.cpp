#include <iostream>
#include <vector>
using namespace std;

void IncTime(int& h, int& m) {
    ++m;
    if (m == 60) {
        m = 0;
        ++h;
        if (h == 24) {
            h = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m;
    cin >> h;
    cin.ignore();
    cin >> m;

    int a;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        IncTime(h, m);
    }
    
    cout << (h / 10) << (h % 10) << ":" << (m / 10) << (m % 10) << endl;

    return 0;
}