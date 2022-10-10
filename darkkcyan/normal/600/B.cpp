#include <bits/stdc++.h>

using namespace std;

#define ffff(i, a, b, c) for (i a; i b; i c)
#define fff(i, a, b) ffff (i, = a, != b, ++)
#define ff(i, n) fff(i, 0, n)
#define all(v) v.begin(), v.end()

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, f, g;  // count variable

    int n, m;
    cin >> n >> m;
    long arr1[n];
    long arr2[m];

    ff (i, n) {
        cin >> arr1[i];
    }

    ff (i, m) {
        cin >> arr2[i];
    }

    sort(arr1, &arr1[n], [] (long a, long b) {return a < b;});

    ff (i, m) {
        int l = 0;
        int r = n - 1;
        while (l != r) {
            int mid = (l + r) / 2;
            if (arr1[mid] > arr2[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // make sure my answer is right
        // I'm stupid, ok
        while (l < n - 1 and arr1[l] <= arr2[i]) ++l;
        while (l >= 0 and arr1[l] > arr2[i]) --l;

        cout << (l + 1) << ' ';
    }

    return 0;
}