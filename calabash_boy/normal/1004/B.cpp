//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i,a,b) for (int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    rep(i, 0, n) cout << (i & 1);
    return 0;
}