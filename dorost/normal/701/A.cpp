#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    vector <pair <int, int>> p;
    int n, avr = 0;
    cin >> n;
    bool f[n];
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = true;
        avr += a[i];
    }
    avr = avr / (n / 2);
    for (int i = 0; i < n; i++) {
        if (!f[i]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (!f[j]) {
                continue;
            }
            if (a[i] + a[j] == avr) {
                f[i] = false;
                f[j] = false;
                p.push_back({i + 1, j + 1});
                break;
            }
        }
    }
    for (int i = 0; i < p.size(); i++){
        cout << p[i].first << ' ' << p[i].second << endl;
    }
}