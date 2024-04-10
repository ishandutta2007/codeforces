#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    string P;
    cin >> P;
    P = 'A' + P + 'A';
    int ans = 1;
    for (int i = 0; i + 1 < P.size(); ++i) {
        if (P[i] != 'A' && P[i] != 'E' && P[i] != 'I' && P[i] != 'O' && P[i] != 'U' && P[i] != 'Y') continue;
        int j = i + 1;
        while (P[j] != 'A' && P[j] != 'E' && P[j] != 'I' && P[j] != 'O' && P[j] != 'U' && P[j] != 'Y') {
            ++j;
        }
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}