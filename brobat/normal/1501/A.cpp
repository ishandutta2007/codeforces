//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100

int n;
int a[MAXN], b[MAXN], ex[MAXN];
int ext;

void dept_time(int i) {
    // Calculates the EXTRA TIME of departure from station i.
    // wt = minimum waiting time (ceil division)
    int wt = (b[i]-a[i])/2;
    if((b[i]-a[i])%2==1) wt += 1;
    if((a[i]+ext+wt)<=b[i]) ext = 0;
    else {
        ext = a[i] + ext + wt - b[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) cin >> a[i] >> b[i];
    forn(i, n) cin >> ex[i];
    ext = 0;
    forn(i, n-1) {
        ext += ex[i];
        dept_time(i);
    }
    ext += ex[n-1];
    cout << (a[n-1]+ext) << endl;
}
    return 0;
}