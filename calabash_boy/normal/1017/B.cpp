//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<r;i++)
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
int n;
typedef long long ll;
int main(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    vector<ll> cnt(4, 0);
    rep(i,0,n) {
        ll r=0;
        if (s[i]=='1') r|=2;
        if (t[i]=='1') r|=1;
        cnt[r]++;
    }
    cout << cnt[0]*cnt[2]+cnt[0]*cnt[3]+cnt[1]*cnt[2] << endl;
    return 0;
}