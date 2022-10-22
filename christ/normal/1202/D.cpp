#include <bits/stdc++.h>
using namespace std;
char b[2000005];
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) {
        int n;
        scanf ("%d",&n);
        int low = 0, high = 50000,ans=0;
        while (low <= high) {
            int mid = (low+high)>>1;
            if (mid * 1LL * (mid-1)/2 <= n) {ans=mid; low=mid+1;}
            else high = mid-1;
        }
        int a = ans * (ans-1) / 2;
        printf ("133");
        for (int i = 0; i < n-a; i++) printf ("7");
        for (int i = 0; i < ans-2; i++) printf ("3");
        printf ("7\n");
    }
    return 0;
}