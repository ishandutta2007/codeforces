#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if(n <= 3) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n";
    if(n%2) {
        cout << "1 * 2 = 2\n3 + 4 = 7\n7 + 5 = 12\n12 * 2 = 24" << endl;
        for(int i=6; i<=n; i+=2)
            cout << i+1 << " - " << i << " = 1\n24 * 1 = 24" << endl;
    } else {
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24" << endl;
        for(int i=5; i<=n; i+=2)
            cout << i+1 << " - " << i << " = 1\n24 * 1 = 24" << endl;
    }
}