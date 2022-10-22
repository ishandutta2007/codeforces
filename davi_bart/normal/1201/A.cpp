#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][6];
vector<int> pt;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
      string p;
      cin>>p;
      for(int j=0;j<M;j++){
        int k=p[j]-'A';
        a[j][k]++;
      }
    }
    for(int i=0;i<M;i++){
      int o;
      cin>>o;
      pt.push_back(o);
    }
    int tot=0;
    for(int i=0;i<M;i++){
      int ma=0;
      for(int j=0;j<5;j++){
        ma=max(ma,a[i][j]);
      }
      tot+=ma*pt[i];
    }
    cout<<tot;
    return 0;
}