#include<bits/stdc++.h>

using namespace std;

int main() {
    int te; cin >> te;
    while (te--) {
        int a, b; cin >> a >> b;
        int ans = b-a;
        for (int i = a; i <= b; i++)
            ans = min(ans, 1-b-a + i + ((i&b)==i? b: i | b& ~((1<<31-__builtin_clz(i&~b))-1)));
        cout << ans << "\n";
    }
}