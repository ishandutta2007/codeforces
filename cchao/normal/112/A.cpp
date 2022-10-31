#include <bits/stdc++.h>
using namespace std;


int main() {
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); ++i)
        a[i] = tolower(a[i]), b[i] = tolower(b[i]);
    cout << strcmp(a.c_str(), b.c_str()) << endl;
    return 0;
}