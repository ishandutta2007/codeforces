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
  ll v[3],l;
  cin>>v[0]>>v[1]>>v[2]>>l;
  ll tot = 0;
  for(ll i = 0;i <= l;++i) tot += (i+1)*(i+2)/2;
  
  for(int i = 0;i <3;++i){
    ll a = v[i];
    ll b = v[(i+1)%3]+v[(i+2)%3];
    ll d = max(0LL,b-a);
    for(ll j = d;j <= l;++j){
      ll r = min(a+j-b,l-j);
      tot -= (r+1)*(r+2)/2;
    }
  }
  cout<<tot<<endl;
}