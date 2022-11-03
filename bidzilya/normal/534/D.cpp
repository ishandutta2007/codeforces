#include <bits/stdc++.h>
using namespace std;

bool SetIndex(vector<vector<int> >& a, int x, int& index)
{
    if (a[x].empty()) {
        return false;
    }
    index = a[x].back();
    a[x].pop_back();
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int> > a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    
    int last = -1;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ++last;
        if (last - 3 < 0) {
            if (a[last].empty()) {
                cout << "Impossible" << endl;
                return 0;
            }
            ans[i] = a[last].back();
            a[last].pop_back();
        } else {
            if (!a[last - 3].empty() && !a[last - 2].empty() && !a[last - 1].empty()) {
                last -= 3;
                ans[i] = a[last].back();
                a[last].pop_back();
            } else {
                if (a[last].empty()) {
                    while (last >= 0 && a[last].empty()) {
                        last -= 3;
                    }
                    if (last < 0) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                    ans[i] = a[last].back();
                    a[last].pop_back();
                } else {
                    ans[i] = a[last].back();
                    a[last].pop_back();
                }
            }
        }
    }
    
    cout << "Possible" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    
    return 0;
}