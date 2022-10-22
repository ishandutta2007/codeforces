#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<bool> a;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N,x,y;
  cin>>N>>x>>y;
  for(int i=0;i<N;i++){
        char o;
  cin>>o;
    a.push_back(o-'0');
  }
  int tot=0;
  reverse(a.begin(),a.end());
  for(int i=0;i<x;i++){
    if(i!=y && a[i]==1)tot++;
    if(i==y && a[i]==0)tot++;
  }
  cout<<tot;
	return 0;
}