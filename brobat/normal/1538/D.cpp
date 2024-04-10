//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define N 200100
#define MOD 1000000007

int a, b, k;

int func(int n) {
    int ans = 0;
    while(n%2==0) {
        ans++;
        n = n/2;
    }
    for(int i=3; (i*i)<=n; i = i+2) {
        while(n%i==0) {
            ans++;
            n = n/i;
        }
    }
    if(n>2) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> a >> b >> k;
    if(a>b) swap(a, b);
    cout << "\n";
    if((a==b)&&(k==1)) {
        cout << "NO";
        continue;
    }
    if(k==1) {
        if(b%a==0) cout << "YES";
        else cout << "NO";
        continue;
    }
    int x, y;
    x = func(a);
    y = func(b);
    if((x+y)>=k) cout << "YES";
    else cout << "NO";
}
    return 0;
}