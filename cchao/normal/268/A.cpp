#include <bits/stdc++.h>
using namespace std;

int a[30], b[30], n;
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(a[i] == b[j]) ans++;
    cout << ans << endl;
    return 0;
}