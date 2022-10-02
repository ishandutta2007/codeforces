#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        vector<int> a(4);
        for (int i = 0; i < 4; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << a[0]*a[2] << "\n";
    }
}