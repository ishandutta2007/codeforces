#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 2010;



int main() {
    ios_base::sync_with_stdio(false);
    map<string, int> C;
    C["Tetrahedron"] = 4;
    C["Cube"] = 6;
    C["Octahedron"] = 8;
    C["Dodecahedron"] = 12;
    C["Icosahedron"] = 20;
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string A;
        cin >> A;
        ans += C[A];
    }
    cout << ans << endl;
    return 0;
}