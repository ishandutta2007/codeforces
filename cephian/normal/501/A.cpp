#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

double pt(int a, int b) {
    return max(0.3 * a, a - b * a / 250.0);
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    double m = pt(a, c);
    double v = pt(b, d);
    if(abs(m - v) < 1e-9) cout << "Tie\n";
    else if(m > v) cout << "Misha\n";
    else cout<< "Vasya\n";
    
    return 0;
}