#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> fact;

void f(int n) {
    int q = sqrt(n);
    for(int i = 2; i <= q; ++i) {
        if(n == 1) break;
        while(n % i == 0) {
            fact.push_back(i);
            n /=i;
        }
    }
    if(n != 1) fact.push_back(n);
}

int main() {
    int n;
    cin >> n;
    f(n);

    int ans = n;
    for(int i = 0; i < fact.size(); ++i) {
        n /= fact[i];
        ans += n;
    }
    cout << ans << "\n";


    return 0;
}