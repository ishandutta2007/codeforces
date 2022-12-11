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
typedef priority_queue<int> pqi;
typedef map<int,int> mii;

int gcd(int a,int b){
  if(b == 0) return a;
  return gcd(b,a%b);
}

int main(){
  int n;
  cin>>n;
  pqi Q;
  mii M;
  for(int i = 0;i < n*n;++i){
    int x;
    cin>>x;
    Q.push(x);
    if(M.count(x) == 0) M[x] = 0;
    ++M[x];
  }
  vi R;
  for(int i = 0;i < n;++i){
    int k = Q.top();
    Q.pop();
    while(M[k] == 0){
      k = Q.top();
      Q.pop();
    }
    for(int j = 0;j < R.size();++j){
      int y = gcd(R[j],k);
      M[y] -= 2;
    }
    R.push_back(k);
    --M[k];
    if(i > 0) cout<<" ";
    cout<<k;
  }
  cout<<endl;
}