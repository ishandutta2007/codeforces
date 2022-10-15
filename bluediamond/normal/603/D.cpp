#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long double ld;
const int N=2000+7;
int n;

ld read_ld(){
  int x;
  cin>>x;
  return x;
}

struct Vector{
  ld x;
  ld y;
};

ld norm(Vector a){
  return sqrt(a.x*a.x+a.y*a.y);
}

Vector operator - (Vector a,Vector b){
  return {a.x-b.x, a.y-b.y};
}

Vector operator / (Vector a,ld b){
  return {a.x/b, a.y/b};
}

Vector normalize(Vector a){
  return a/norm(a);
}


Vector pts[N];

ld trap(Vector a,Vector b) {
  return (a.x-b.x)*(a.y+b.y);
}

ld trap(Vector a, Vector b, Vector c){
  return trap(a,b)+trap(b,c)+trap(c,a);
}

const ld eps=1e-14;

bool operator < (Vector a, Vector b){
  if(abs(a.x-b.x)<eps) return a.y<b.y;
  return a.x<b.x;
}

bool operator == (Vector a,Vector b){
  return abs(a.x-b.x)<eps&&abs(a.y-b.y)<eps;
}

Vector rep(Vector a){
  if(a.x>0){
    a.x*=-1;
    a.y*=-1;
  }
  if(abs(a.x)<eps){
    if(a.y>0){
      a.x*=-1;
      a.y*=-1;
    }
  }
  return a;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }
  cin>>n;
  for (int i=1;i<=n;i++){
    ld a=read_ld();
    ld b=read_ld();
    ld c=read_ld();
    ld x=-c*a/(a*a+b*b);
    ld y=-c*b/(a*a+b*b);
    pts[i]={x, y};
    ///cout<<fixed<<setprecision(6)<<a*x+b*y+c<<" and "<<b*x-a*y<<"\n";
    ///cout<<fixed<<setprecision(6)<<x<<" "<<y<<"\n";
  }




  long long sol=0;
  for (int i=1;i<=n;i++){
    vector<Vector> g;
    int extra=0;
    for(int j=i+1;j<=n;j++){
      if(pts[i]==pts[j]) extra++;
      else {
        g.push_back(rep(normalize(pts[j]-pts[i])));
      }
    }
    sort(g.begin(),g.end());

    /// use two extra
    sol+=extra*(extra-1)/2;

    /// use one extra
    sol+=extra*(int)g.size();

    int l=0;
    while(l<(int)g.size()){
      int r=l;
      while(r+1<(int)g.size()&&abs(g[r+1].x-g[r].x)<eps&&abs(g[r+1].y-g[r].y)<eps) r++;
      int cnt=r-l+1;
      sol+=cnt*(cnt-1)/2;
      l=r+1;
    }
  }
  cout<<sol<<"\n";

}