#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 110000;
const int INF = 1000000000;

int x[MAXN];
int y[MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i % k] += x[i];
    }
    
    int temp = INF, yy = 0;
    for (int i = 0; i < k; ++i) {
        if (y[i] < temp) {
            temp = y[i];
            yy = i;
        }
    }
    
    cout << yy+1 << endl;
    
    return 0;
}