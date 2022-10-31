#include <iostream>
using namespace std;

int main() {
    int n, ans=0, c=0;
    cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        c = c + b - a;
        ans = max(ans, c);
    }
    cout << ans << endl;
    return 0;
}