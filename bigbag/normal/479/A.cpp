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

int a, b, c;
set<int> s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    s.insert(a + b + c);
    s.insert(a + b * c);
    s.insert((a + b) * c);
    s.insert(a * b + c);
    s.insert(a * (b + c));
    s.insert(a * b * c);
    cout << *s.rbegin() << endl;
    return 0;
}