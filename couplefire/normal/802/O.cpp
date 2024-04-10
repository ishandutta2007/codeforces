#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 500005

int n, k; 
int arr[MAXN], brr[MAXN];
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;

array<int, 2> check(int mid){
    int cnt = 0, res = 0;
    while(!pq.empty()) pq.pop();
    for(int i = 0; i<n; i++){
        pq.push({arr[i]-mid, 0});
        int val = brr[i]+pq.top()[0];
        if(val < 0){
            res += val;
            if(pq.top()[1] == 0) cnt++;
            pq.pop(); pq.push({-brr[i], 1});
        }
    }
    return {cnt, res};
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++) cin >> brr[i];
    int lo = 0, hi = 2e9+9;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)[0] < k) lo = mid+1;
        else hi = mid;
    }
    cout << check(lo)[1]+lo*k << endl;
}