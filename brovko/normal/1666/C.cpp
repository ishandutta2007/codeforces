#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x[3], y[3];

    for(int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    vector <pair <int, int> > v;

    for(int i = 0; i < 3; i++)
        v.push_back({x[i], y[i]});

    sort(v.begin(), v.end());

    for(int i = 0; i < 3; i++)
    {
        x[i] = v[i].first;
        y[i] = v[i].second;
    }

    int k = 0;

    if(max({y[0], y[1], y[2]}) != min({y[0], y[1], y[2]}))
        k++;

    if(x[0] != x[1])
        k++;

    if(x[1] != x[2])
        k++;

    cout << k << "\n";

    if(max({y[0], y[1], y[2]}) != min({y[0], y[1], y[2]}))
        cout << x[1] << ' ' << min({y[0], y[1], y[2]}) << ' ' << x[1] << ' ' << max({y[0], y[1], y[2]}) << "\n";

    if(x[0] != x[1])
        cout << x[0] << ' ' << y[0] << ' ' << x[1] << ' ' << y[0] << "\n";

    if(x[1] != x[2])
        cout << x[2] << ' ' << y[2] << ' ' << x[1] << ' ' << y[2];
}