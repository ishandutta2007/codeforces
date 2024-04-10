#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int p[n+1];
    p[0] = 0;
    for(int i = 1; i <= n; ++i) {
        p[i] = -1e9;
        if(i >= a)
            p[i] = max(p[i], p[i-a]+1);
        if(i >= b)
            p[i] = max(p[i], p[i-b]+1);
        if(i >= c)
            p[i] = max(p[i], p[i-c]+1);
    }
    cout << p[n] << "\n";
    
}