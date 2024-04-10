#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>v;
unordered_map<int,int> volte;
vector<int> somme;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N,I;
  cin>>N>>I;
  I*=8;
  I/=N;
  int div;
  if(I>29)div=1000000;
  else div=pow(2,I);
  int a;
  for(int i=0;i<N;i++){
    cin>>a;
    v.push_back(a);
    volte[a]++;
  }
  sort(v.begin(),v.end());
  v.resize(unique(v.begin(),v.end())-v.begin());
  if(div>=v.size()){
    cout<<0;
    return 0;
  }
  somme.push_back(0);
  for(int i=0;i<v.size();i++){
    somme.push_back(somme[i]+volte[v[i]]);
  }
  int togli=v.size()-div;
  int tot=1000000;
  for(int i=0;i<=togli;i++){
    int sx=i,dx=togli-i;
    int g=somme[sx]+somme[v.size()]-somme[v.size()-dx];
    tot=min(tot,g);
  }
  cout<<tot;
  return 0;
}