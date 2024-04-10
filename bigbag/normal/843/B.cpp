#include <ctime>
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

const int max_n = 50055, inf = 1011111111;
const int it = 1000;

int Q, n, start, x, used[max_n];
vector<int> v;

int my_rand() {
    return (rand() << 16) + rand();
}

pair<int, int> querry(int pos) {
    ++Q;
    if (Q >= 1999) {
        exit(228);
    }
    used[pos] = 1;
    cout << "? " << pos << endl;
    cout.flush();
    int v, next;
    cin >> v >> next;
    if (v == -1 && next == -1) {
        exit(228);
    }
    return make_pair(v, next);
}

void ans(int x) {
    cout << "! " << x << endl;
    cout.flush();
    exit(0);
}

int main() {
    srand(time(NULL));
    //srand(22222345);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> start >> x;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    int best = start, mx = -1;
    used[start] = 1;
    for (int i = 0; v.size() && i < it; ++i) {
        int num = my_rand() % v.size();
        while (used[v[num]]) {
            swap(v[num], v.back());
            v.pop_back();
            if (v.size() == 0) {
                break;
            }
            num = my_rand() % v.size();
        }
        if (v.size() == 0) {
            break;
        }
        pair<int, int> p = querry(v[num]);
        if (p.first <= x && p.first >= mx) {
            best = v[num];
            mx = p.first;
        }
        if (p.second != -1) {
            used[p.second] = 1;
        }
    }
    while (true) {
        pair<int, int> p = querry(best);
        if (p.first >= x) {
            ans(p.first);
        }
        if (p.second == -1) {
            ans(-1);
        }
        best = p.second;
    }
    return 0;
}