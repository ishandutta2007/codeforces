#include <iostream>
#include <iomanip>
#include <cstring>
#define int long long
using namespace std;

int bcj[100005], sz[100005];

int root(int x) {
    if(bcj[x] == x) return x;
    else return (bcj[x] = root(bcj[x]));
}

int mx = 0;

void merge(int a, int b) {
    int ra = root(a), rb = root(b);
    if(ra != rb) { 
        //cout << "Merge " << a << ' ' << b << ' ' << sz[ra] << ' ' << sz[rb] << ' ' << sz[ra]+sz[rb] << endl;
        bcj[ra] = rb; 
        sz[rb] += sz[ra]; 
        mx = max(mx, sz[rb]);
    }
}

int value[100005], order[100005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    memset(sz, -1, sizeof sz);
    for(int i=0; i<=n; i++) bcj[i] = i;
    for(int i=1; i<=n; i++) cin >> value[i];
    for(int i=0; i<n; i++) cin >> order[i];
    for(int i=n-1; i>=0; i--) {
        //for(int i=1; i<=n; i++) cout << setfill(' ') << setw(3) << sz[root(i)] << ' ';
        //cout << endl;
        int cur = order[i];
        order[i] = mx; 
        sz[cur] = value[cur];
        if(cur != 1 && sz[cur-1] != -1) merge(cur, cur-1);
        if(cur != n && sz[cur+1] != -1) merge(cur, cur+1);
        mx = max(mx, sz[root(cur)]);
    }
    for(int i=0; i<n; i++) cout << order[i] << endl; 
}