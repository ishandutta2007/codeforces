#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> aray;
int n, m;

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int v; cin >> v; aray.push_back(v);
    }
    sort(aray.begin(), aray.end());
    int mv = 1000000000;
    for(int i=0; i+n-1<m; i++)
        mv = min(mv, aray[i+n-1]-aray[i]);
    cout << mv << endl;
}