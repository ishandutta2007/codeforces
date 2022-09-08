#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, k, h[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    /*

    for (int i = 0; i < 5; ++i) {
        a.insert(1); //    ,  
    }

    cout << a.size() << endl; // 5

    a.erase(a.find(1));
    cout << a.size() << endl; // 4    

    a.erase(1);

    cout << a.size() << endl; // 0    

    for (int i = 5; i < 10; ++i) {
        a.insert(i);
    }

    cout << *a.begin() << " " << *a.rbegin() << endl; // 5 9  ,    

    */

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int l = 0, r = 0, ans = 0;
    multiset<int> a;
    a.insert(h[0]);
    while (l < n) {
        while (*a.rbegin() - *a.begin() <= k && r < n) {
            r++;
            a.insert(h[r]);
        }
        ans = max(ans, r - l);
        a.erase(a.find(h[l]));
        l++;
    }

    l = r = 0;
    int cnt = 0;
    multiset<int> b;
    vector < pair<int, int> > ans1;
    b.insert(h[0]);
    while (l < n) {
        while (*b.rbegin() - *b.begin() <= k && r < n) {
            r++;
            b.insert(h[r]);
        }
        if (r - l == ans) {
            cnt++;
            ans1.push_back(make_pair(l + 1, r));
        }
        b.erase(b.find(h[l]));
        l++;
    }
    cout << ans << ' ' << cnt << endl;
    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i].first << ' ' << ans1[i].second << endl;
    }
    return 0;
}