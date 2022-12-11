#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
  int n;
  cin>>n;
  vi T(n);
  vi R(n,0);
  for(int i = 0;i < n;++i){
    cin>>T[i];
  }
  int k = 0;
  int ch = 0;
  while(k < n){
    for(int i = 0;i < n;++i){
      if(R[i] == 0 and T[i] <= k){
	++k;
	R[i] = 1;
      }
    }
    if(k == n) break;
    ++ch;
    for(int i = n-1;i >= 0;--i){
      if(R[i] == 0 and T[i] <= k){
	++k;
	R[i] = 1;
      }
    }
    if(k == n) break;
    ++ch;
  }
  cout<<ch<<endl;
}