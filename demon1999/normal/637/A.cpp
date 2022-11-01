#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

int a[2000000];

int main()
{
    int n;
    cin >> n;
    int ans1 = -1;
    int ans;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
        if (a[x] > ans1) {
            ans1 = a[x];
            ans = x;
        }
    }
    cout << ans << endl;

    return 0;
}