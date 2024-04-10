#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

struct node {
    int a, b, c;
};

vector<node> solve() {
    int n;
    map<int, int> m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    int ans = 0;
    int l = 1;
    int r = n/3;

    while (l <= r) {
        int mid = (l + r) / 2;

        int cnt = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            cnt += min(mid, it->second);

        if (cnt >= 3 * mid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    vector<int> v;

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        for (int i = 0; i < min(ans, it->second); i++)
            v.push_back(it->first);

    vector<node> result;
    for (int i = 0; i < ans; i++)
    {
        node nd;
        nd.a = v[ans*2 + i];
        nd.b = v[ans*1 + i];
        nd.c = v[ans*0 + i];
        result.push_back(nd);
    }
    return result;
}

int main() {

    vector< node > v = solve();

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i].a << ' ' << v[i].b << ' ' << v[i].c << '\n';

    return 0;
}