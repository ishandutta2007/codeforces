#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long double ld;
typedef unsigned long long ll;
typedef vector<ld> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef priority_queue<pi> pqi;

vvpi G;
vll C;
vll A;
vi V;
ll n;

ll dfs(int x){
  V[x] = 1;
  ll ret = 1;
  for(int i = 0;i < G[x].size();++i){
    int y = G[x][i].X;
    int k = G[x][i].Y;
    if(V[y] == 0){
      ll q = dfs(y);
      ret += q;
      ll r1 = n-q;
      ld r = (r1*q*(q-1))+(q*r1*(r1-1));
      C[k] += r;
    }
  }
  return ret;
}

int main(){
  cin>>n;
  G = vvpi(n);
  C = vll(n,0);
  V = vi(n,0);
  A = vll(n);
  
  ld div = n*(n-1)*(n-2)/6;
  
  for(int i = 1;i < n;++i){
    int x,y,k;
    cin>>x>>y>>k;
    --x;
    --y;
    A[i] = k;
    G[x].push_back(pi(y,i));
    G[y].push_back(pi(x,i));
  }
  
  dfs(0);
  
  ld res = 0;
  for(int i = 1;i < n;++i){
    res += ld(A[i]*C[i])/div;
  }
  
  int m;
  cin>>m;
  
  for(int i = 0;i <m;++i){
    int x;
    ll k;
    cin>>x>>k;
    res -= ld(A[x]*C[x])/div;
    A[x] = k;
    res += ld(A[x]*C[x])/div;
    
    cout<<setprecision(10)<<fixed<<res<<endl;
  }
}