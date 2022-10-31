#include <bits/stdc++.h>
using namespace std;

int t[100005],n,sum,app;

int main() {
  cin>>n;
  for(int i=1;i<=n;i++) cin>>t[i];
  sort(t+1,t+n+1);
  for(int i=1;i<=n;i++){
    if(t[i]>=app){
      sum++;
      app+=t[i];
    }
  }
  cout<<sum<<'\n';
}