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
  int n,k;
  cin>>n>>k;
  vi R(n);
  for(int i = 0;i < n;++i){
    cin>>R[i];
  }
  int p = n*min(300,k);
  vi T;
  
  for(int i = 0;i < p;++i){
    int j = R[i%n];
    int a = -1;
    int b = T.size();
    while(a+1<b){
      int c = (a+b)/2;
      if(T[c] <= j) a = c;
      else b = c;
    }
    if(b == T.size()) T.push_back(j);
    else T[b] = j;
  }
  
  sort(R.begin(),R.end());
  int pa = 0;
  int ant = -1;
  int m = 0;
  for(int i = 0;i < n;++i){
    if(R[i] != ant){
      m = max(m,pa);
      pa = 1;
      ant = R[i];
    }
    else ++pa;
  }
  m = max(m,pa);
  int res = T.size();
//   cout<<res<<endl;
  res += m*(k - min(300,k));
  cout<<res<<endl;
}