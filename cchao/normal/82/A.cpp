#include <bits/stdc++.h>
using namespace std;


string s[] = {
 "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

int main() {
    int n; cin >> n;
    int i = 1;
    while(n > i*5) {
        n -= i*5;
        i *= 2;
    }
    cout << s[(n-1) / i] << endl;
    return 0;
}