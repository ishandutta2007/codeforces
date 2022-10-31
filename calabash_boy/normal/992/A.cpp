//
// Created by calabash_boy on 18-6-19.
//
/*header*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int MOD = 1e9+7;
const int maxn =10000;
typedef vector<int> vi;
#define rep(x,y,z) for (int x=y;x<z;x++)
int main(){


    int n;
    cin >> n;
    vi a(n);

    rep(i,0,n)
    cin >> a[i];

    set<int> s;
    for(auto&v :a)
        if(v)s.insert(v);

    cout << s.size() << endl;
}