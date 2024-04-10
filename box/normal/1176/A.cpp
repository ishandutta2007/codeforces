#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        long long n; cin >> n;
        int count = 0;
        while(n != 1) {
            long long best = n+1;
            if(n%2 == 0) best = min(best, n/2);
            else if(n%3 == 0) best = min(best, (2*n)/3);
            else if(n%5 == 0) best = min(best, (4*n)/5);
            if(best == n+1) {
                count = -1;
                break;
            }
            n = best;
            count++;
        }
        cout << count << endl;
    }
}