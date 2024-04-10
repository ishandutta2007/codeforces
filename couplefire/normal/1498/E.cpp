#include <bits/stdc++.h>
using namespace std;

const int N = 500+5;

int n;
array<int, 2> arr[N];
int psum[N];
vector<array<int, 2>> ranges;
array<int, 3> ans = {-1, -1, -1};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i][0], arr[i][1] = i;
    sort(arr, arr+n);
    psum[0] = arr[0][0];
    for(int i = 1; i<n; i++) psum[i] = psum[i-1]+arr[i][0];
    int nxt = n-1;
    for(int i = n-1; i>=0; i--){
        if(i == 0 || psum[i-1] == i*(i-1)/2) ranges.push_back({i, nxt}), nxt = i-1;
    }
    for(auto x : ranges){
        if(x[0] == x[1]) continue;
        ans = max(ans, array<int, 3>{arr[x[1]][0]-arr[x[0]][0], arr[x[0]][1], arr[x[1]][1]});
    }
    cout << "! " << ans[1]+1 << " " << ans[2]+1 << endl;
}