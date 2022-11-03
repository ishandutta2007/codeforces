#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int h = 1;
    --n;
    while (true) {
        int cur = (h + 1) * (h + 2) / 2;

        if (cur <= n) {
            n -= cur;
            ++h;
        } else {
            break;
        }
    }

    cout << h << endl;

    return 0;
}