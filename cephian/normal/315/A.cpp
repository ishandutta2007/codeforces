#include <iostream>
#include <algorithm>

using namespace std;

int a[100];
int b[100];

int typ[1005];

int main() {
    fill(typ, typ + 1005, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++typ[b[i]];
    }
    int un = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i])
            un += typ[a[i]] <= 1;
        else
            un += typ[a[i]] == 0;
    }
    cout << un << "\n";
    return 0;
}