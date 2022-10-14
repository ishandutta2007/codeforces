#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int b, g, n; cin >> b >> g >> n;
    int tot = 0;
    for(int boys=0; boys<=n; boys++)
        if(boys <= b && (n-boys) <= g) tot++;
    cout << tot << endl;
}