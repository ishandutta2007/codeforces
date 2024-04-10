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
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = -1;
const int MOD = -1;
int n;
int main(){
    int n; cin >> n;
    vector<vector<ll> > a(n,vector<ll>(4,0));
    for (int i=0;i<n;i++) for (int j=0;j<4;j++) cin >> a[i][j];
    ll r=0; ll ans=1;
    for (int i=0;i<4;i++) r+=a[0][i];
    for (int i=1;i<n;i++) {
        ll d=0;
        for (int j=0;j<4;j++) d+=a[i][j];
        if (d>r) ans++;
    }
    cout << ans << endl;

}