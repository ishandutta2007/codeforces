#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int q;
    scanf ("%d",&q);
    while (q--) {
        int n;
        scanf ("%d",&n);
        vector<int> a(n);
        for (auto &i : a) scanf ("%d",&i);
        for (int i = 0; i < n; i++) {
            a.push_back(a[i]);
            bool inc = 1, dec = 1;
            for (int j = i+1; j < i+n; j++) {
                if (a[j] > a[j-1]) dec = 0;
                if (a[j] < a[j-1]) inc = 0;
            }
            if (inc || dec) {printf ("YES\n"); goto done;}
        }
        printf ("NO\n");
        done:;
    }
    return 0;
}