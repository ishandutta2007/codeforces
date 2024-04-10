#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        long long s = (1 + 2 * k - 1) * k / 2;
        if (n >= s && (n - s) % 2 == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}