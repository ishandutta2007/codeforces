#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    vector<int> xs;
    xs.push_back(x1);
    xs.push_back(x2);
    xs.push_back(x3);
    sort(xs.begin(), xs.end());
    cout << xs[2] - xs[0] << endl;
    return 0;
}