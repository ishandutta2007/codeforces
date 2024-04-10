#include <bits/stdc++.h>

using namespace std;

struct Shirt {
    int price, a, b;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;

    vector<int> price(n);
    vector<int> has[3];

    for (int i = 0; i < n; ++i)
        cin >> price[i];

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        has[a - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        has[b - 1].push_back(i);
    }

    vector<char> taken(n, 0);

    for (int i = 0; i < 3; ++i) {
        sort(has[i].begin(), has[i].end(), [&](int a, int b) {
            return price[a] > price[b];
        });
    }

    int m;
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        --c;

        int choose = -1;
        while (has[c].size()) {
            int top = has[c].back();
            if (!taken[top]) {
                taken[top] = true;
                cout << price[top] << " ";
                choose = 1;
                break;
            } else has[c].pop_back();
        }
        if (choose == -1) {
            cout << -1 << " ";
        }
    }
    cout << endl;

    
	
	return 0;
}