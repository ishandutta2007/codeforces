#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> q(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        q[i] = (100 - p) / 100.0;
    }

    cout << fixed << setprecision(15);
    const int N = 3e5;

    vector<double> curPow(n);
    for (int i = 0; i < n; ++i) {
        curPow[i] = q[i];
    }
    double lastP = 1.0;
    for (int i = 0; i < n; ++i) {
        lastP *= (1.0 - curPow[i]);
    }
    double prevPSum = 0.0;

    for (int itr = n + 1; itr <= N; ++itr) {
        double newLastP = 0.0;
        int index = -1;
        for (int i = 0; i < n; ++i) {
            double curLastP = lastP / (1.0 - curPow[i]);
            curLastP *= (1.0 - curPow[i] * q[i]);

            if (index == -1 || curLastP > newLastP) {
                newLastP = curLastP;
                index = i;
            }
        }
        prevPSum += lastP;
        lastP = newLastP;
        curPow[index] *= q[index];
    }

    cout << lastP * N - prevPSum << endl;

    return 0;
}