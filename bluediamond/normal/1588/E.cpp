#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int N=3000+7;
int n;
ld radius;

struct vec{
  ld x;
  ld y;
};


vec operator - (vec a, vec b){
  return {a.x-b.x,a.y-b.y};
}

vec operator + (vec a, vec b){
  return {a.x+b.x,a.y+b.y};
}

ld dot(vec a,vec b){
  return a.x*b.x+a.y*b.y;
}

ld cross(vec a,vec b){
  return a.x*b.y-a.y*b.x;
}

vec a[N];

vec getp(vec a){
  return {-a.y,a.x};
}

vec getnormed(vec a){
  ld mult=(ld)1/sqrt(dot(a,a));
  return {a.x*mult,a.y*mult};
}

const ld pi=2*acos(0);
bool ok[N][N];

ld get(vec v){
  ld sol=atan2(v.y,v.x);
  if (sol<0)sol+=2*pi;
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  int iradius;
  cin>>n>>iradius;
  radius=iradius;
  for (int i=1;i<=n;i++){
    cin>>a[i].x>>a[i].y;
  }
  for (int i=1;i<=n;i++){
    bool first=1;
    ld low=-1e9,high=+1e9;
    function<bool(ld, ld)>eok=[&](ld l, ld r){
      if (high<l||r<low)return 0;
      return 1;
    };
    for (int j=1;j<=n;j++){
      if (i==j)continue;
      ld l,r;
      vec dist=a[j]-a[i];
      if(dot(dist,dist)<=radius*radius)continue;
      vec rrr=getp(getnormed(dist));
      rrr.x*=radius;
      rrr.y*=radius;

      ld curand=get(dist);

      ld mn=asin(radius/sqrt(dot(dist,dist)));

      l=curand-mn;
      r=curand+mn;


      if(first){
        low=l;
        high=r;
      }else{
        if(eok(l,r)){
          low=max(low,l);
          high=min(high,r);
        }else{
          if(eok(l+2*pi,r+2*pi)){
            low=max(low,l+2*pi);
            high=min(high,r+2*pi);
          }else{
            low=max(low,l-2*pi);
            high=min(high,r-2*pi);
          }
        }
      }
      first=0;
    }
    if(low>high)continue;
    for (int j=1;j<=n;j++){
      if (i==j)continue;
      vec dist=a[j]-a[i];
      ld ang=get(dist);
      ok[i][j]|=(low<=ang&&ang<=high);

      ok[i][j]|=(low<=ang-2*pi&&ang-2*pi<=high);
      ok[i][j]|=(low<=ang+2*pi&&ang+2*pi<=high);
    }
  }

  int sol=0;
  for (int i=1;i<=n;i++){
    for (int j=1;j<i;j++){
      sol+=(ok[i][j]&ok[j][i]);
    }
  }
  cout<<sol<<"\n";

  return 0;
}