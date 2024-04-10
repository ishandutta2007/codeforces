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

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b,a%b);
}

int main(){
  int n;
  cin>>n;
  int k[n];
  cin>>k[0];
  int d = k[0];
  for(int i = 1;i < n;++i){
    cin>>k[i];
    d = gcd(d,k[i]);
  }
  bool xec = true;
  for(int i = 0;i < n;++i){
    int q = k[i]/d;
    while(q%2 == 0) q /= 2;
    while(q%3 == 0) q /= 3;
    if(q > 1) xec = false;
  }
  if(xec) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}