//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 120

int n;
int arr[MAXN];
int grr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) cin >> arr[i];
    sort(arr, arr+n);
    int num = 0;
    cout << arr[0] << " ";
    forn(i, n-1) {
        if(arr[i+1]==arr[i]) {
            grr[num] = arr[i+1];
            num += 1;
        }
        else {
            cout << arr[i+1] << " ";
        }
    }
    forn(i, num) {
        cout << grr[i] << " ";
    }
    cout << endl;
} 
    return 0;
}