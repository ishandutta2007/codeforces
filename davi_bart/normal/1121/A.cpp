#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
int stud[1000];
int s[1000];
vector<pair<int,int> >scuole[100000];
int main(){
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int N,M,K;
  cin>>N>>M>>K;
  for(int i=1;i<=N;i++){
    cin>>stud[i];
  }
  for(int i=1;i<=N;i++){
    cin>>s[i];
    scuole[s[i]].push_back({stud[i],i});
  }
  for(int i=0;i<=M;i++){
    sort(scuole[i].begin(),scuole[i].end());
    reverse(scuole[i].begin(),scuole[i].end());
  }
  int tot=0;
  for(int i=0;i<K;i++){
    int a;
    cin>>a;
    if(scuole[s[a]][0].second==a)continue;
    tot++;
  }
  cout<<tot;
  return 0;
}