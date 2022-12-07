#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define INF 200000000000
#define BIGINF 1000000000000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    ll n, k;
    cin >> n >> k;
    ll a[k], t[k];
    forn(i, k) cin >> a[i];
    forn(i, k) cin >> t[i];
    ll arr[n+50];
    forn(i, n+50) arr[i] = INF;
    priority_queue <pair<ll, ll>> pq;
    forn(i, k) {
        arr[a[i]] = t[i];
        pq.push({-t[i], a[i]});
    }
    while(!pq.empty()) {
        ll temp = pq.top().first; //temperature 
        temp *= -1;
        ll pos = pq.top().second; //position
        pq.pop();
        if(arr[pos+1]>(temp+1)) {
            arr[pos+1] = temp + 1;
            if(pos<=n) pq.push({(temp+1)*-1, pos+1});
        }
        if(arr[pos-1]>(temp+1)) {
            arr[pos-1] = temp + 1;
            if(pos>0) pq.push({(temp+1)*-1, pos-1});
        }
    }
    for(ll i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}
    return 0;
}