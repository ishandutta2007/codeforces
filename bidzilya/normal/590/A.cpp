#include <vector>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = a[1];
    a[n + 1] = a[n];

    vector<pair<int, int> > pos;
    for (int i = 0; i <= n; ++i) {
        int j = i;
        while (j <= n && a[j + 1] == a[i]) {
            ++j;
        }
        if (j != i) {
            pos.push_back(make_pair(i, j));
        }
        i = j;
    }
    
    int itrs = 0;
    for (int i = 1; i < (int) pos.size(); ++i) {
        int prev = pos[i - 1].second + 1;
        int cur = pos[i].first - 1;
        int lf = a[pos[i - 1].second];
        int rg = a[pos[i].first];
        if (prev <= cur) {
            int len = cur - prev + 1;
            itrs = max(itrs, len / 2);

            for (int j = prev; j < prev + len / 2; ++j) {
                a[j] = lf;
            }
            for (int j = cur; j > cur - len / 2; --j) {
                a[j] = rg;
            }
            if (len & 1) {
                int middle = (prev + cur) / 2;

                if ((len / 2) & 1) {
                    a[middle] = 1 - a[middle];
                }
                if (lf == rg) {
                    if (a[middle] != lf) {
                        itrs = max(itrs, len / 2 + 1);
                        a[middle] = lf;
                    }
                }
            }
        }
    }

    cout << itrs << endl;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    

    return 0;
}