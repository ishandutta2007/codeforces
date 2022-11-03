#include <vector>
#include <iostream>
#include <string>
using namespace std;

const string YES = "yes";
const string NO = "no";

const string PRIME = "prime";
const string COMPOSITE = "composite";

bool IsPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    /*
    for (int i = 2; i <= 100; ++i) {
        if (IsPrime(i)) {
            cout << i << endl;
        }
    }
    return 0;
    */

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> smallPrimes = {2, 3, 5, 7};
    const vector<int> maxPower = {6, 4, 2, 2};
    vector<int> curPower = {0, 0, 0, 0};

    for (int i = 0; i < (int) smallPrimes.size(); ++i) {
        int x = smallPrimes[i];

        while (true) {
            cout << x << endl;

            string res;

            cin >> res;

            if (res == YES) {
                ++curPower[i];
                if (maxPower[i] == curPower[i]) {
                    break;
                }
                x *= smallPrimes[i];
            } else {
                break;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < (int) smallPrimes.size(); ++i) {
        if (curPower[i] > 1) {
            cout << COMPOSITE << endl;
            return 0;
        } else if (curPower[i] == 1) {
            ++count;
        }
    }

    if (count > 1) {
        cout << COMPOSITE << endl;
        return 0;
    }

    if (count == 0) {
        cout << PRIME << endl;
        return 0;
    }

    int curPrime;
    for (int i = 0; i < (int) smallPrimes.size(); ++i) {
        if (curPower[i] > 0) {
            curPrime = smallPrimes[i];
            break;
        }
    }

    for (int i = 10; i <= 100; ++i) {
        if (IsPrime(i) && i * curPrime <= 100) {
            cout << i << endl;

            string res;
            cin >> res;

            if (res == YES) {
                cout << COMPOSITE << endl;
                return 0;
            }
        }
    }

    cout << PRIME << endl;

    return 0;
}