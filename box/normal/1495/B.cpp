#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)

int ar[100005];
int A[100005], B[100005];
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n; cin >> n;
    rep(i, n) cin >> ar[i];
    for(int i=n-2; i>=0; i--) {
        if(ar[i] > ar[i+1]) B[i] = B[i+1] + 1;
        else B[i] = 0;
    }
    rep1(i, n-1) {
        if(ar[i-1] < ar[i]) A[i] = A[i-1] + 1;
        else A[i] = 0;
    }
    multiset<int> q;
    rep(i, n) {
        if(!(i == 0 || i == n-1 || (ar[i-1] < ar[i] && ar[i] > ar[i+1]))) continue;
        q.insert(A[i]);
        q.insert(B[i]);
    }
    int ans = 0;
    rep(i,n) {
        if(!(i == 0 || i == n-1 || (ar[i-1] < ar[i] && ar[i] > ar[i+1]))) continue;
        q.erase(q.find(A[i]));
        q.erase(q.find(B[i]));
        int mx = 0;
        if(q.size()) mx = *q.rbegin();
        if(mx >= A[i] && mx >= B[i]) ;
        else {
            int x = max(A[i], B[i]), y = min(A[i], B[i]);
            // if(n == 7) cout << i << ' ' << x << ' ' << y << endl;
            if(x == y) {
                if(x % 2 == 0) ans++;
            } else {
                // if(x == 2) ans++;
            }
        }
        q.insert(A[i]);
        q.insert(B[i]);
    }
    cout << ans << endl;
    return 0;
}