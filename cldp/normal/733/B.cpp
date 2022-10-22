#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int X[1000001], Y[1000001];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &X[i], &Y[i]);
    }
    long long L = 0, R = 0;
    for (int i = 1; i <= N; ++i) {
        L += X[i];
        R += Y[i];
    } 
    int cnt = 0;
    long long ans = abs(L - R);
    for (int i = 1; i <= N; ++i) {
        L = L - X[i] + Y[i];
        R = R - Y[i] + X[i];
        if (abs(L - R) > ans) {
            ans = abs(L - R);
            cnt = i;
        }
        L = L - Y[i] + X[i];
        R = R - X[i] + Y[i];
    }
    cout << cnt << endl;
    return 0;
}