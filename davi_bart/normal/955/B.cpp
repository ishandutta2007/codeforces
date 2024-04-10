#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string a;
    cin>>a;
    if(a.size()<4){
      cout<<"No";
      return 0;
    }
    vector<int> p(30,0);
    for(int i=0;i<a.size();i++)p[a[i]-'a']++;
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    if(p[4]>0 || (p[2]==0 && p[1]==1) || p[1]==0){
      cout<<"No";
      return 0;
    }
    cout<<"Yes";
}