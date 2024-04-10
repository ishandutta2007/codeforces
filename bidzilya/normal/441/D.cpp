#include <bits/stdc++.h>
using namespace std;

vector<bool> used;

int GetCycles(const vector<int>& a, vector<int>& cycle_num)
{
    int n = a.size();
    used.assign(n, false);
    int last_cycle_num = -1;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            --ans;
            ++last_cycle_num;
            int j = i;
            while (!used[j]) {
                cycle_num[j] = last_cycle_num;
                used[j] = true;
                j = a[j];
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    int m;
    cin >> m;

    vector<int> cycle_num(n);
    int cm = GetCycles(a, cycle_num);

    cout << abs(m - cm) << endl;
    while (cm < m) {
        bool found = false;
        for (int i = 1; i < n; ++i) {
            if (cycle_num[i] != cycle_num[0]) {
                cout << 1 << " " << i + 1 << " ";
                swap(a[0], a[i]);
                int new_cm = GetCycles(a, cycle_num);
                assert(new_cm == cm + 1);
                cm = new_cm;
                found = true;
                break;
            }
        }
        assert(found);
    }
    while (cm > m) {
        bool found = false;
        vector<int> amount(n, 0);
        for (int i = 0; i < n; ++i) {
            ++amount[cycle_num[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (amount[cycle_num[i]] > 1) {
                for (int j = i + 1; j < n; ++j) {
                    if (cycle_num[i] == cycle_num[j]) {
                        cout << i + 1 << " " << j + 1 << " ";
                        swap(a[i], a[j]);
                        int new_cm = GetCycles(a, cycle_num);
                        assert(new_cm == cm - 1);
                        cm = new_cm;
                        found = true;
                        break;
                    }
                }
                break;
            }
        }
        assert(found);
    }
    cout << endl;

    return 0;
}