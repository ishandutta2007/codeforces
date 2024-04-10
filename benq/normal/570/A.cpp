#include <iostream>

using namespace std;

int m, n;
int winners[101];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int maxindex = 1;
        int max = 0;
        for (int j = 1; j <= n; ++j) {
            int a;
            cin >> a;
            if (a > max) {
                maxindex = j;
                max = a;
            }
        }
        winners[maxindex]++;
    }
    
    int max = 1;
    for (int i = 2; i <= n; ++i) {
        if (winners[i] > winners[max]) {
            max = i;
        }
    }
    
    cout << max << endl;
    return 0;
}