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

vvi D;
vi V;

int f(int x, int e, int k, int q, int et){
  if(x == k and e == et) return 0;
  if(x == k) return -1;
  //cout<<x<<" "<<e<<endl;
  if(D[x][e] > -2) return D[x][e];
  int r = 0;
  int y = x*q+e;
  for(int i = y+1;i <y+q;++i) r+= abs(V[i-1]-V[i]);
  D[x][e] = r+f(x+1,e,k,q,et);
  if(D[x][e] < r and e == et) return D[x][e] = -1;
  if(e < et and f(x+1,e+1,k,q,et) >= 0 and D[x][e] >= r) return D[x][e] = min(D[x][e],r+abs(V[y+q]-V[y+q-1])+f(x+1,e+1,k,q,et));
  else if(e < et and f(x+1,e+1,k,q, et) >= 0 )return D[x][e] = r+abs(V[y+q]-V[y+q-1])+f(x+1,e+1,k,q,et);
  else if(D[x][e] < r) return D[x][e] = -1;
  return D[x][e];
}

int main(){
  int n,k;
  cin>>n>>k;
  V = vi(n);
  for(int i = 0;i < n;++i) cin>>V[i];
  sort(V.begin(),V.end());
  int q = n/k;
  int e = n%k;
  //cout<<q<<" "<<e<<endl;
  D = vvi(k,vi(e+1,-2));
  cout<<f(0,0,k,q,e)<<endl;
}