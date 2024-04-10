#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005
#define INF 4000000000000000009ll

int n, k;
int arr[MAXN], cur[MAXN];
array<int, 2> tmp[MAXN];

int eval(int m, int x){
    if(x > m) return -INF;
    return m-3*x*x+3*x-1;
}

int get(int m, int mid){
    if(m < mid+1) return 0;
    return min(m, (int)(0.5+sqrt(m/3.0-mid/3.0-3.0/36.0)));
}

int check(int mid){
    int cnt = 0;
    for(int i = 0; i<n; i++) cur[i] = get(arr[i], mid), cnt += cur[i];
    return cnt;
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> arr[i];
    int lo = -INF, hi = INF;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid) > k) lo = mid+1;
        else hi = mid;
    }
    k -= check(lo);
    for(int i = 0; i<n; i++) tmp[i] = {eval(arr[i], cur[i]+1), i};
    sort(tmp, tmp+n); reverse(tmp, tmp+n);
    for(int i = 0; i<k; i++) cur[tmp[i][1]]++;
    for(int i = 0; i<n; i++) cout << cur[i] << " ";
    cout << endl;
}