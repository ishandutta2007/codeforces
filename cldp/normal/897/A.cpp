#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
 
string Q;

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    cin >> Q;
    for (int i = 0; i < M; ++i) {
        int a, b;
        char c, d;
        cin >> a >> b >> c >> d;
        for (int j = a - 1; j < b; ++j) {
            if (Q[j] == c) Q[j] = d;
        }
    }
    cout << Q << endl;
    return 0;
}