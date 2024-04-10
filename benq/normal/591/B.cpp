#include <iostream>

using namespace std;

string asdf="abcdefghijklmnopqrstuvwxyz";

int findIndex(char x) {
    for (int i = 0; i < 26; ++i) {
        if (asdf[i] == x) return i;
    }
    return 0;
}

int main() {
    int n, m;
    string name;
    cin >> n >> m >> name;

    for (int i = 0; i < m; ++i) {
        char a, b;
        cin >> a >> b;
        int c = findIndex(a);
        int d = findIndex(b);
        asdf[c]=b;
        asdf[d]=a;
    }

    for (int i = 0; i < n; ++i) {
        char v = name[i];
        cout << asdf[v-'a'];
    }
}