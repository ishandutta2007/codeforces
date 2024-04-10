#include <bits/stdc++.h>
using namespace std;

int window[1000006];
int arr[200005];
int uniq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(window, 0, sizeof window);
        int n, k, d; cin >> n >> k >> d;
        for(int i=0; i<n; i++) cin >> arr[i];
        uniq = 0;
        for(int i=0; i<d; i++) {
            window[arr[i]]++;
            if(window[arr[i]] == 1) uniq++;
        }
        int best = uniq;
        for(int i=d; i<n; i++) {
            if(window[arr[i-d]]-- == 1) uniq--;
            if(window[arr[i]]++ == 0) uniq++;
            best = min(best, uniq);
        }
        cout << best << endl;
    }
}