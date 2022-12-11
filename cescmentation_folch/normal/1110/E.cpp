#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> V1(n-1), V2(n-1);

    int x;
    cin >> x;
    int ant1 = x;
    int fi1 = x;
    for (int i = 0; i < n-1; ++i) {
        int y;
        cin >> y;
        fi1 = y;
        V1[i] = y-x;
        x = y;
    }

    cin >> x;
    int ant2 = x;
    int fi2 = x;
    for (int i = 0; i < n-1; ++i) {
        int y;
        cin >> y;
        fi2 = y;
        V2[i] = y-x;
        x = y;
    }

    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());

    if (ant1 == ant2 and fi1 == fi2 and V1 == V2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}