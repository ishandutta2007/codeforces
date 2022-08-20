#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

long long int a[200001];

int main() {
    long long int n, sum=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[b] = i;
    }
    for (int i = 1; i < n; ++i) {
        sum += abs(a[i+1]-a[i]);
    }
    cout << sum;
}