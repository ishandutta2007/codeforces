#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

int arr[200005];
int n;


int gap(int i) {
    return arr[i+1] - arr[i];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr+n);
    int len = n-2 - (n-1)/2+1;
    int ans = 0x7fffffff;
    for(int i = len; i < n; ++i)
        ans = min(ans, arr[i] - arr[i-len]);
    cout << ans << "\n";
    return 0;
}