#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int Pow(int x,int n) {
    int ans = 1;
    while (n) {
        if (n&1) ans = (1ll * ans * x) % mod;
        x = (1ll * x * x) % mod;
        n >>= 1;
    }
    return ans;
}
vector<int> uoc;
map<int,int> F;
void update(int &x) {
    if (x<0) x += mod;
    if (x>mod) x-= mod;
}
int f(int x) {
    if (x==1) return 1;
    if (F.find(x) != F.end()) return F[x];
    int ans = Pow(2,x-1);
    for(int i=1; i<uoc.size(); i++) {
        if (x%uoc[i]==0) {
            ans -= f(x / uoc[i]);
            update(ans);
        }
    }
    F[x] = ans;
    return ans;
}
int main() {
    int x, y;
    cin >> x >> y;
    if (y%x) {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=sqrt(y);i++) {
        uoc.push_back(i);
        if (y % i ==0) {
            if (y /i != i) {
                uoc.push_back(y/i);
            }
        }
    }
    
    sort(uoc.begin(), uoc.end());
    cout<<f(y/x);
}