// https://codeforces.com/contest/1520/problem/E

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1000100
#define MOD 1000000007

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    int arr[MAXN];
    char temp;
    int k = 0;
    forn(i, n) {
        cin >> temp;
        if(temp=='*') arr[k++] = i;
    }
    int m = (k%2)?((k+1)/2):(k/2);
    long long ans = 0;
    forn(i, m-1) ans += (arr[m-1]-arr[i]-1-i);
    for(int i = m; i<k; i++) ans += (arr[i]-arr[m-1]+m-i-1);
    cout << ans << endl; 
}
    return 0;
}