#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<long long> pq;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    reverse(arr, arr+n);
    for(int i = 0; i<k+1; i++){
        pq.push(0);
    }
    long long ans = 0;
    for(int i = 0; i<n; i++){
        long long a = pq.top();
        pq.pop();
        ans += a;
        a += arr[i];
        pq.push(a);
    }
    cout << ans << endl;
}