/************
*           *
*   HELLO   *
*           *
************/

#include <bits/stdc++.h>

using namespace std;

const int mx = 300000;
int n;
pair<double, double> data[mx];

bool check(double t) {
    vector<pair<double, int> > events;
    for (int i = 0; i < n; ++i) {
        events.push_back(make_pair(data[i].first - t * data[i].second, 0));
        events.push_back(make_pair(data[i].first + t * data[i].second, 1));
    }
    sort(events.begin(), events.end());
    int k = 0;
    for (int i = 0; i < events.size(); ++i) {
        if (events[i].second == 0)
            k++;
        else
            k--;
        if (k == n)
            return 1;
    }
    return 0;
}



int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> data[i].second;
    }
    double l = 0.0, r = 1000000000.0, EPS = 0.0000001;
    while ((r - l) > EPS) {
        double mid = (l + r) / 2;
        if (check(mid) == 1)
            r = mid;
        else
            l = mid;
    }
    printf("%f", l);
    return 0;
}