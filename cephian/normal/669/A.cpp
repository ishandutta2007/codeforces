#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll k;
    cin >> k;
    cout << 2*(k/3) + k%3 - (k%3==2) <<"\n";
}