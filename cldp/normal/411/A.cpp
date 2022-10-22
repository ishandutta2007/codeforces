#include <string>
#include <iostream>
using namespace std;

int main() {
    string P;
    cin >> P;
    bool a, b, c, d;
    a = b = c = d = false;
    for (int i = 0; i < P.size(); ++i) {
        if (P[i] >= '0' && P[i] <= '9') a = true;
        if (P[i] >= 'A' && P[i] <= 'Z') b = true;
        if (P[i] >= 'a' && P[i] <= 'z') c = true;
    }
    if (a && b && c && P.size() >= 5) cout << "Correct" << endl; else cout << "Too weak" << endl;
    return 0;   
}