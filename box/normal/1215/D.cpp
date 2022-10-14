#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int lsum = 0, rsum = 0, ld = 0, rd = 0;
    for(int i=0; i<n/2; i++) {
        char c; cin >> c;
        if(c == '?') ld++;
        else lsum += (c-'0');
    }
    for(int i=n/2; i<n; i++) {
        char c; cin >> c;
        if(c == '?') rd++;
        else rsum += (c-'0');
    }
    int mov = 0;
    while(ld+rd) {
        if(mov % 2 == 0) {
            // Monocarp's turn
            if(lsum < rsum) {
                // Obviously try to increase r as long as bicarp can't match it
                if(rd) {
                    rd--;
                    rsum += 9;
                } else {
                    // Can I win by spamming this with 9's? Right is fixed already
                    if(9*ld/2 + lsum > rsum) lsum += 9;
                    ld--;
                }
            } else {
                // Similar
                if(ld) {
                    ld--;
                    lsum += 9;
                } else {
                    if(9*rd/2 + rsum > lsum) rsum += 9;
                    rd--;
                }
            }
        } else {
            // Bicarp's turn
            if(lsum < rsum) {
                if(ld) {
                    // Put exactly what's needed
                    lsum += min(9, rsum-lsum);
                    ld--;
                } else rd--; // don't make the problem worse
            } else {
                if(rd) {
                    rsum += min(9, lsum-rsum);
                    rd--;
                } else ld--;
            }
        }
        mov++;
    }
    if(lsum == rsum) cout << "Bicarp" << endl;
    else cout << "Monocarp" << endl;
}