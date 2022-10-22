#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,M;
    cin>>N>>M;
    vector<int>a(N),b(M);
    for(int &i:a)cin>>i;
    for(int &i:b)cin>>i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(b[0]>a.back() && a[0]*2<b[0]){
      cout<<max(a[0]*2,a.back());
    }else{
      cout<<-1;
    }
}