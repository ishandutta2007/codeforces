#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int k;
    cin >> k;
    int m[12];
    for(int i = 0; i < 12; ++i)
        cin >> m[i];
    
    sort(m, m + 12);
    int i = 12;
    int h = 0;
    while(h < k && i > 0) {
        --i;
        h += m[i];
    }
    if(h < k)
        cout << "-1\n";
    else
        cout << 12 - i << "\n";
    
    return 0;
}