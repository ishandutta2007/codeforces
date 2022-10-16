//  228

// Problem: C. Replacement
// Contest: Codeforces - Codeforces Beta Round #97 (Div. 2)
// URL: https://codeforces.com/contest/136/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto& ch:v)	cin>>ch;
    auto it = max_element(v.begin(),v.end());
    if(*it==1)
    	*it = 2;
    else *it = 1;
    sort(v.begin(),v.end());
    for(int j:v)	cout<<j<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
   // cin>>T;
    while(T--){
        solve();
    }
}