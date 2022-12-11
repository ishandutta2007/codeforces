#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vpi T;
vpi V;

void build(int node, int a, int b){
  if(a == b){
    T[node] = pi(0,V[a].Y);
    return;
  }
  build(2*node,a,(a+b)/2);
  build(2*node+1,1+(a+b)/2,b);
  T[node] = max(T[2*node],T[2*node+1]);
}

pi xec(int node, int a, int b, int x, int y){
  if(b < x or y < a or x > y) return pi(-1,-1);
  if(x <= a and b <= y) return T[node];
  return max(xec(2*node,a,(a+b)/2,x,y),xec(2*node+1,1+(a+b)/2,b,x,y));
}

void act(int node, int a, int b, int x, int k){
  if(b < x or x < a) return;
  if(a == b){
    T[node].X = k;
    //cout<<"act->"<<T[node].X<<" "<<T[node].Y<<endl;
    return;
  }
  act(2*node,a,(a+b)/2,x,k);
  act(2*node+1,1+(a+b)/2,b,x,k);
  T[node] = max(T[2*node],T[2*node+1]);
}

int main(){
  int n;
  cin>>n;
  ll d;
  cin>>d;
  V = vpi(n);
  for(int i = 0;i < n;++i){
    cin>>V[i].X;
    V[i].Y = i;
  }
  T = vpi(4*n);
  vi R(n,-1);
  vi P(n);
  sort(V.begin(),V.end());
  for(int i = 0;i < n;++i) P[V[i].Y] = i;
  build(1,0,n-1);
  
  //for(int i = 0;i < n;++i) cout<<i<<" "<<P[i]<<"("<<V[i].X<<" "<<V[i].Y<<") ";
  //cout<<endl;
  
  for(int i = 0;i < n;++i){
    ll mi = V[P[i]].X-d;
    ll ma = V[P[i]].X+d;
    int a = 0,b = n;
    while(a+1<b){
      int c = (a+b)/2;
      if(V[c].X >= ma) b = c;
      else a = c;
    }
    int y = b;
    a = -1;
    b = n-1;
    while(a+1<b){
      int c = (a+b)/2;
      if(V[c].X <= mi) a = c;
      else b = c;
    }
    int x = a;
    //cout<<i<<" "<<x<<" "<<y<<endl;
    pi r = max(xec(1,0,n-1,0,x),xec(1,0,n-1,y,n-1));
    //cout<<r.X<<" "<<r.Y<<endl;
    if(r.X == 0){
      act(1,0,n-1,P[i],1);
    }
    else {
      act(1,0,n-1,P[i],r.X+1);
      R[i] = r.Y;
    }
  }
  pi r = xec(1,0,n-1,0,n-1);
  vi res(r.X);
  int k = r.Y;
  for(int i = r.X-1;i >= 0;--i){
    res[i] = k;
    k = R[k];
  }
  cout<<r.X<<endl;
  for(int i = 0;i < r.X;++i){
    if(i > 0) cout<<" ";
    cout<<res[i]+1;
  }
  cout<<endl;
}