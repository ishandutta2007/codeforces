#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v[30];
int main(){
  //freopen("ciao.txt", "r", stdin);
  //freopen("sol.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  string base;
  cin>>base;
  for(int i=0;i<30;i++)v[i].push_back(0);
  for(int i=0;i<N;i++)v[base[i]-'a'].push_back(i);
  int M;
  cin>>M;
  string a;
  for(int i=0;i<M;i++){
    cin>>a;
    vector<int> volte(30,0);
    for(int j=0;j<a.size();j++){
      volte[a[j]-'a']++;
    }
    int ma=0;
    for(int j=0;j<30;j++){
      int p=volte[j];
      if(v[j][p]>ma)ma=v[j][p];
    }
    cout<<ma+1<<endl;
  }
  return 0;
}