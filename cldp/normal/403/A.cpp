#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;

int N, P;

int cal(int a) {
    if (a > N) a -= N;
    return a;
}


int main() {
    int times;
    cin >> times;
    while (times--) {
        cin >> N >> P;
        for (int i = 1; i <= N; ++i) {
            cout << i << " " << cal(i + 1) << endl;
        }
        for (int i = 1; i <= N; ++i) {
            cout << i << " " << cal(i + 2) << endl;
        }
        int L = 3;
        while (P > 0) {
            for (int i = 1; i <= N; ++i) {
                cout << i << " " << cal(i + L) << endl;
                --P;
                if (P == 0) break;
            }
            ++L;
        }
    }

    return 0;
}