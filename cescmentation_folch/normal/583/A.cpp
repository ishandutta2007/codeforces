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
  vi v(51,0);
  vi h(51,0);
  int n;
  cin>>n;
  int t = 0;
  for(int i = 1;i <= n*n;++i){
    int x,y;
    cin>>x>>y;
    if(v[x] == 0 and h[y] == 0){
      v[x] = 1;
      h[y] = 1;
      if(t > 0) cout<<" ";
      cout<<i;
      ++t;
    }
  }
  cout<<endl;
}