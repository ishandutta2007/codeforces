#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1, inf = 1011111111;

int n;
string a, b;
set<string> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    q.insert(a);
    q.insert(b);
    cin >> n;
    while (n--) {
        cout << *q.begin() << " " << *q.rbegin() << endl;
        cin >> a >> b;
        q.erase(a);
        q.insert(b);
    }
    cout << *q.begin() << " " << *q.rbegin() << endl;
    return 0;
}