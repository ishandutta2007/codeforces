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
  int a[n];
  for(int i = 0;i < n;++i) cin>>a[i];
  int r = 0;
  while(true){
    int  maxi = 0; 
    for(int i = 1;i < n;++i){
      if(a[i] >= a[maxi]) maxi = i;
    }
    if(maxi == 0) break;
    ++r;
    ++a[0];
    --a[maxi];
  }
  cout<<r<<endl;
}