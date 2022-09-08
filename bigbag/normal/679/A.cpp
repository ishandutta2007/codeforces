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

const int max_n = 1, inf = 1111111111;

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int n;
vector<int> q, w;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i <= 10; ++i) {
        if (is_prime(i)) {
            q.push_back(i);
        }
    }
    for (int i = 2; i <= 50; ++i) {
        if (is_prime(i)) {
            w.push_back(i);
        }
    }
    int x = -1;
    for (int i = 0; i < q.size(); ++i) {
        cout << q[i] << endl;
        cout.flush();
        string s;
        cin >> s;
        if (s == "yes") {
            x = q[i];
            break;
        }
    }
    if (x == -1) {
        cout << "prime" << endl;
        cout.flush();
        return 0;
    }
    for (int i = 0; i < w.size(); ++i) {
        if (x * w[i] <= 100) {
            cout << x * w[i] << endl;
            cout.flush();
            string s;
            cin >> s;
            if (s == "yes") {
                cout << "composite" << endl;
                cout.flush();
                return 0;
            }
        }
    }
    cout << "prime" << endl;
    cout.flush();
    return 0;
}