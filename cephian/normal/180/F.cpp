#include <iostream>

using namespace std;

const int N = 100005;
int p[N], a[N], b[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin>> a[i];
    for(int i = 1; i <= n; ++i)
        cin>> b[i];
    for(int i = 1; i <= n; ++i)
        p[a[i]] = b[i];
    for(int i = 1; i <= n; ++i)
        cout << p[i] << " ";
    return 0;
}