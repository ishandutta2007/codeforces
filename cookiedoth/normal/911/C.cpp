#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

int a[3], cnt[2000];

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    if (cnt[1] >= 1) {
        cout << "YES" << endl;
        return 0;
    }
    if (cnt[2] >= 2) {
        cout << "YES" << endl;
        return 0;
    }
    if (cnt[3] >= 3) {
        cout << "YES" << endl;
        return 0;
    }
    if (cnt[2] >= 1 && cnt[4] >= 2) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}