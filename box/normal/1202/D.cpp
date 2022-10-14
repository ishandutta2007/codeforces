#include <iostream>
#include <cmath>
#include <cstdio>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int i; cin >> i;
        if(i == 1) puts("1337");
        else {
            // binary search # of 3s
            int low = 2, high = 500000, threes = -1;
            while(low <= high) {
                int mid = (low+high)>>1;
                if(((mid*(mid-1))/2) <= i) {
                    threes = mid;
                    low = mid+1;
                } else high = mid -1;
            }
            putchar('1'); putchar('3'); putchar('3');
            int q = (threes*(threes-1))/2; q = i-q;
            while(q--) putchar('7');
            threes -= 2;
            while(threes--) putchar('3');
            putchar('7'); putchar('\n');
        }
    }
}