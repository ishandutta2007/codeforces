#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    puts(min(a,b) % 2 == 1 ? "Akshat" : "Malvika");
    return 0;
}