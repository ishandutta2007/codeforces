//  228

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <thread>
#include <math.h>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n{}, a[101];
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long total{ 0 };
    for(int i = 1; i <= n; i++) {
        total += (a[i] - 1) * i;
        ++total;
    }
    cout << total << endl;
    return 0;
}