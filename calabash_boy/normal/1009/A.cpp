//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = -1;
const int MOD = -1;
#define rep(i,l,r) for (int i=l;i<r;i++)
#define vi vector<int>
int main(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    int ans = 0;
    int ps = 0;
    for (int i = 0; i < n; ++i) {
        if (ps == m) {
            break;
        }
        if (b[ps] >= a[i]) {
            ps++;
            ans++;
        }
    }
    cout << ans << endl;

}