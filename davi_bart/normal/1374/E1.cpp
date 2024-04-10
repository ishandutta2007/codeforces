#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> v[4];
int N,K;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++){
      int a,b,c;
      cin>>a>>b>>c;
      if(b&c)v[3].push_back(a);
      else if(b)v[1].push_back(a);
      else if(c)v[2].push_back(a);
      else v[0].push_back(a);
    }
    int mi=1e12;
    int cur=0;
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());
    sort(v[3].begin(),v[3].end());
    for(int i=0;i<min(K,(int)v[3].size());i++)cur+=v[3][i];
    int pos=0;
    if(v[3].size()<K){
        int i=v[3].size();
        while(v[1].size()>pos && v[2].size()>pos && i+pos<K){
        cur+=v[1][pos]+v[2][pos];
        pos++;
      }
      if(pos+i<K){
        cout<<-1;
        return 0;
      }
    }
    mi=min(mi,cur);
    for(int i=min(K,(int)v[3].size())-1;i>=0;i--){
      cur-=v[3][i];
      while(v[1].size()>pos && v[2].size()>pos && i+pos<K){
        cur+=v[1][pos]+v[2][pos];
        pos++;
      }
      if(pos+i<K)break;
      mi=min(mi,cur);
    }
    if(mi==1e12)cout<<-1;
    else cout<<mi;
}