#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int change(char p) {
    switch (p) {
        case '[' : return 2;
        case '8' : return 1;
        case '(' : return 0;
    }
    return 0;
}

int main() {
    string P, Q;
    cin >> P >> Q;
    int ans = 0;
    for (int i = 0; i < P.size(); i += 2) {
         int a, b;
         a = change(P[i]);
         b = change(Q[i]);
         if (a == b) continue;
         if (a == (b + 1) % 3) --ans; else ++ans;
    }
    if (ans > 0) cout << "TEAM 1 WINS" << endl;
    if (ans < 0) cout << "TEAM 2 WINS" << endl;
    if (ans == 0) cout << "TIE" << endl;
    return 0;
}