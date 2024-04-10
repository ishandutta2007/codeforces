#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mx = 120000;

int main()
{
    int n, a[mx], i, j;
    bool flag;
    vector<int> v;
    v.clear();
    cin >> n;
    for (i = 0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (i = 0; i<n; i++) {
        flag = 1;
        for (j = 0; j<v.size(); j++) {
            if (a[i] == v[j]) {
                flag = 0;
            }
        }
        if (flag == 1) {
            v.push_back(a[i]);
            if (v.size()>3) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (v.size()<3) {
        cout << "YES";
        return 0;
    }
    if ((v[2] - v[1]) == (v[1] - v[0])) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}