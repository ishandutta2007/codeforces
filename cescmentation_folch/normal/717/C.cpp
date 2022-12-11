#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    vector <long long>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) ans += a[i]*a[n-1-i];
    cout << ans%10007 << endl;
}