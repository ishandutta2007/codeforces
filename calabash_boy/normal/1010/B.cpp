#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
int a[maxn],b[maxn],m;
#define rep(i,l,r) for (int i=l;i<r;i++)
typedef long double db;
typedef vector<int> vi;
int x, n;
vi ret;
void input(){
    cin >> x >> n;
    ret.resize(n);
    for (auto &x:ret){
        x=0;
    }
}
int solve(){
    rep(i, 0, n) {
        int x1 = 1;
        cout << x1 << endl;
        cin >> x1;
        ret[i] = x1;
        if (!ret[i])return 0;
    }
    int l=0,r=x+1,gg=-1;
    while(l^r){
        int mid=l+r>>1;
        int x1 = mid;
        cout << x1 << endl;
        cin >> x1;
        int m = x1;
        if(!m)return 0;
        ++gg;
        if(gg>=n)gg=0;
        if(ret[gg]==-1)m=-m;
        if(m!=1)r=mid;
        else l=mid+1;
    }
    int x2 = l;
    cout << x2 << endl;
}
int main() {
    input();
    solve();

}