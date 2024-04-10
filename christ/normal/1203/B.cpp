#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int freq[10005],area;
int main() {
    int q;
    scanf ("%d",&q);
    while (q--) {
        memset(freq,0,sizeof freq);
        int n,b;
        scanf ("%d",&n);
        vector<int> a;
        for (int i = 0; i < n * 4; i++) {
            scanf ("%d",&b);
            freq[b]++;
        }
        for (int i = 1; i <= 10000; i++) {
            if (freq[i]&1) {printf ("NO\n"); goto fail;}
            for (int j = 0; j < freq[i]/2; j++) a.push_back(i);
        }
        n = a.size();
        area = a[0] * a[n-1];
        for (int i = 1; i < n/2; i++) {
            if (a[i] * a[n-1-i] != area) {printf ("NO\n"); goto fail;}
        }
        printf ("YES\n");
        fail:;
    }
    return 0;
}