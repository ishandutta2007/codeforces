#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define For(i,a,f) for(int i = a; i < f; ++i)
#define foR(i,a,f) for(int i = a; i > f; --i)

int main(){
  int n,t;
  cin>>n>>t;
  if(t ==  10 and n == 1) cout<<-1<<endl;
  else if(t == 10){
    for(int i = 1;i < n;++i) cout<<1;
    cout<<0<<endl;
  }
  else {
    for(int i = 0;i < n;++i) cout<<t;
    cout<<endl;
  }
}