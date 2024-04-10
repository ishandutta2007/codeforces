
#include <iostream>
#include <vector>

using namespace std;

#define shipp make_pair

int main() {

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
/*
    vector<pair<int, int> > pairs;

    pairs.push_back(shipp(h[0], 0));
    for(int i = 1; i < n; ++i) {
        pairs.push_back(max(shipp(h[i], i), pairs.back()));
    }

    int countr = 0;

    int cur = n - 1;

    while(true) {
        pair<int, int> pai = pairs[cur];

    }
*/

    vector<int> maxs(n);
    vector<int> mins(n);

    maxs[0] = h[0];
    for(int i = 1; i < n; ++i) {
        maxs[i] = max(maxs[i - 1], h[i]);
    }

    mins[n - 1] = h[n - 1];
    for(int i = n - 2; i>=0; --i) {
        mins[i] = min(h[i], mins[i + 1]);
    }

    int countr = 1;

    for(int i = 0; i < n - 1; ++i) {
        if (maxs[i] <= mins[i + 1]) {
            ++countr;
        }
    }

    cout << countr;

    return 14 / 88;

}