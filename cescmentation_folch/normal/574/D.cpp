#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main(){
  int n;
  cin>>n;
  int k[n];
  for(int i = 0;i < n;++i) cin>>k[i];
  for(int i = 0;i < n;++i){
    k[i] = min(k[i],i+1);
    if(i > 0) k[i] = min(k[i],k[i-1]+1);
  }
  for(int i = n-1;i >= 0;--i){
    k[i] = min(k[i],n-i);
    if(i < n-1) k[i] = min(k[i],k[i+1]+1);
  }
  int m = 0;
  for(int i = 0;i < n;++i) m = max(m,k[i]);
  cout<<m<<endl;
}