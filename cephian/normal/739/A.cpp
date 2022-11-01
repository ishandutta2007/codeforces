#include <iostream>

using namespace std;

const int N = 1000005;
int n,m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int lg = 0x7fffffff;
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        lg = min(lg,v-u+1);
    }
    cout << lg << "\n";
    for(int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << i%lg;
    }
    cout << endl;
}