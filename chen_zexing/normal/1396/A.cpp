#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
long long a[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    if (n == 1) {
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("%lld\n",-a[1]);
        return 0;
    }
    cout << "1" << " " << n - 1 << endl;
    for (int i = 1; i < n; i++) {
        long long t = a[i] % n;
        if (t < 0) t += n;
        printf("%lld ", t * (n - 1));
        a[i] += t * (n - 1);
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << n - a[n] << endl;
    a[n] = n;
    cout << "1" << " " << n << endl;
    for (int i = 1; i <= n; i++) printf("%lld ", -a[i]);
    cout << endl;
    return 0;
}