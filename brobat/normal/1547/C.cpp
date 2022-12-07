#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int k, n, m;

int foo() {
    cin >> k >> n >> m;
    int arr[n];
    int brr[m];
    vector<int> ans;
    bool possible = true;
    forn(i, n) cin >> arr[i];
    forn(i, m) cin >> brr[i];
    int i=0;
    int j=0;
    while(i<n||j<m) {
        if(i<n&&arr[i]==0) {
            k += 1;
            ans.push_back(0);
            i += 1;
        }
        else if(i<n&&arr[i]<=k) {
            ans.push_back(arr[i]);
            i += 1;
        }
        else if(j<m&&brr[j]==0) {
            ans.push_back(0);
            k += 1;
            j += 1;
        }
        else if(j<m&&brr[j]<=k) {
            ans.push_back(brr[j]);
            j += 1;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto i: ans) cout << i << " ";
    cout << endl;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    foo();
}
    return 0;
}