#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned int ui32;

void print(ui32 m) {
    if (m) {
        printf("%u.%u.%u.%u\n", m>>24, (m>>16)&255, (m>>8)&255, m&255);
    } else {
        cout << -1 << endl;
    }
}

ui32 read(const string& s) {
    ui32 a, b, c, d;
    sscanf(s.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    return (a << 24) + (b << 16) + (c << 8) + d;
}

int main() {
    vector<ui32> ad;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ad.push_back(read(s));
    }
    
    for (int l = 1; l < 32; ++l) {
        ui32 m = 0;
        for (int i = 0; i < l; ++i)
            m |= 1 << (31 - i);
            
        vector<ui32> nets;
        for (int i = 0; i < n; ++i)
            nets.push_back(ad[i] & m);
            
        sort(nets.begin(), nets.end());
        if (unique(nets.begin(), nets.end()) - nets.begin() == k) {
            print(m); return 0;
        }
    }
    
    print(0);
    return 0;
}