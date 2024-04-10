//

#include <bits/stdc++.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

long long n;
long long arr[MAXN];
priority_queue<long long> pq;
long long ans;
long long health;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    ans = 0;
    health = 0;
    forn(i, n) cin >> arr[i];
    forn(i, n) {
        if(arr[i]<0) {
            if(health + arr[i] >= 0) {
                pq.push(-arr[i]);
                ans += 1;
                health += arr[i];
            }
            else {
                pq.push(-arr[i]);
                long long temp = pq.top();
                pq.pop();
                health = health + arr[i] + temp;
            }
        }
        else {
            ans += 1;
            health += arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}