#include <iostream>
using namespace std;

bool ok(int x) {
    bool vis[10] = {};
    while(x) {
        if(vis[x%10]) return false;
        vis[x%10] = true;
        x /= 10;
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    ++x;
    while(!ok(x)) ++x;
    cout << x << endl;
    return 0;
}