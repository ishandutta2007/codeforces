#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    long long N, K;
    cin >> N >> K;
    long long A = N / 2;
    long long B = A / (K + 1);
    long long C = B * K;
    cout << B << " " << C << " " << N - B - C << endl;
    return 0;
}