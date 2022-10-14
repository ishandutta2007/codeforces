#include <iostream>
using namespace std;

long long daru(int a, int b) { return a/b + (bool)((int)(a%b)); }

int main() {
    long long a, b, c; cin >> a >> b >> c;
    cout << daru(a,c)*daru(b,c) << endl;
}