#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> s;
    int n = s.length();
    int arr[n];
    forn(i, n) {
        char temp = s[i];
        arr[i] = int(temp) - 97;
    }
    // forn(i, n) cout << arr[i] << " ";
    int neg = true;
    int grr[n];
    forn(i, n) grr[i] = arr[i];
    sort(grr, grr+n);
    forn(i, n) {
        if(grr[i]!=i) {
            cout << "NO" << endl;
            neg = false;
            break;
        }
    }
    if(neg==false) continue;
    neg = true;
    if(n<3) {
        cout << "YES" << endl;
        continue;
    }
    bool y = true;
    forn(i, n-1) {
        if(arr[i]==0) neg = false;
        if(neg) {
            if(arr[i+1]>arr[i]) y = false;
        }
        else {
            if(arr[i+1]<arr[i]) y = false;
        }
    }
    if(y==false) cout << "NO" << endl;
    else cout << "YES" << endl;
}
    return 0;
}