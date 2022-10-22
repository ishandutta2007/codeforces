#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    cin>>N;
    vector<int>p;
    for(int i=2;i<=N;i+=2)p.push_back(i);
    for(int i=1;i<=N;i+=2)p.push_back(i);
    for(int i=2;i<=N;i+=2)p.push_back(i);
    cout<<p.size()<<'\n';
    for(int i:p)cout<<i<<" ";
}