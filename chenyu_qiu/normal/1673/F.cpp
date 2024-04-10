#include<bits/stdc++.h>
using namespace std;
int B[33][33], vis[33][33], tot = 0;
int val[33];
int build(int l, int r){
    if (l == r) return -1;
    if (l + 1 == r) {
        val[l] = 0;
        return 0;
    }
    int mid = l + ((r - l) >> 1);
    int mx = max(build(l, mid), build(mid + 1, r)); 
    val[mid] = mx + 1;
    return mx + 1;
}
int vx[50], vy[50];
int px[1024], py[1024];
int main(){
    int n, k;
    cin >> n >> k;
    build(1, n);
    int sum = 0;
    for (int i = 1; i < n; i++) vx[i+1] = vx[i] ^ (1<<(2*val[i])), vy[i+1] = vy[i] ^ (1<<(2*val[i]+1));
    for (int i = 1; i <= n; i++) {
        px[vy[i]] = i;
        py[vx[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < n; j++) cout << (1<<(2*val[j])) << ' ', sum += (1<<(2*val[j]));
        cout << endl;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n; j++) cout << (1<<(2*val[i]+1)) << ' ', sum += (1<<(2*val[i]+1));
        cout << endl;
    }
    int nx = 0, ny = 0;
    while(k--){
        int x;
        cin >> x;
        int d0 = 0, d1 = 0;
        for (int i = 0; i < 32; i++) if (i & 1){
            if ((x >> i) & 1) d1 ^= (1 << i);
        }else{
            if ((x >> i) & 1) d0 ^= (1 << i);
        }
        nx ^= d0;
        ny ^= d1;
        cout << px[ny] << ' ' << py[nx] << endl;

    }
    
}