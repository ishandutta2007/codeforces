#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long int n, array1[200001], ans, change;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> array1[i];
    }
   
    for (int i = 1; i <= n; ++i) {
        int z = array1[i];
        ans += abs(z+change);
        change = -z;
    }
        
    cout << ans;
}