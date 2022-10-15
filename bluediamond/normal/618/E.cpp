#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long double ld;

struct Vector{
  ld x;
  ld y;
};

Vector rot(Vector a, ld ang){
  ld cs=cos(ang);
  ld sn=sin(ang);
  ld x=a.x;
  ld y=a.y;


  return {cs*x+sn*y, -sn*x+cs*y};
}

ld norm(Vector a) {
  return sqrt(a.x*a.x+a.y*a.y);
}

Vector operator + (Vector a, Vector b){
  return {a.x+b.x, a.y+b.y};
}

Vector operator - (Vector a, Vector b){
  return {a.x-b.x, a.y-b.y};
}

Vector operator * (Vector a, ld b){
  return {a.x*b, a.y*b};
}

Vector operator * (ld b, Vector a){
  return {a.x*b, a.y*b};
}

Vector operator / (Vector a, ld b){
  return {a.x/b, a.y/b};
}

Vector normalize(Vector a){
  return a/norm(a);
}

const int N=(int)3e5+7;
const ld pi=(ld)2*acos((ld)0);

ld sqr(ld x){
  return x*x;
}

int n;
int q;
ld lazy[4 * N][2][3];
ld value[N][2];

void reset_lazy(int v){
  lazy[v][0][0]=0; lazy[v][0][1]=0; lazy[v][0][2]=0;
  lazy[v][1][0]=0; lazy[v][1][1]=0; lazy[v][1][2]=0;

  lazy[v][0][0]=1;
  lazy[v][1][1]=1;
}

void push(int v,int tl,int tr){
  ld aux[2];

  ld temp[2][3];


  if(tl==tr){

    aux[0]=value[tl][0]*lazy[v][0][0]+value[tl][1]*lazy[v][0][1]+lazy[v][0][2];
    aux[1]=value[tl][0]*lazy[v][1][0]+value[tl][1]*lazy[v][1][1]+lazy[v][1][2];

    value[tl][0]=aux[0];
    value[tl][1]=aux[1];

  }else{
    assert(tl<tr);

    for (int v2=2*v;v2<=2*v+1;v2++){
/**
      (a0, a1)
      ->
      (a0*lazy[v2][0][0]+a1*lazy[v2][0][1]+lazy[v2][0][2], a0*lazy[v2][1][0]+a1*lazy[v2][1][1]+lazy[v2][1][2])


      (b0, b1)
      ->
      ((a0*lazy[v2][0][0]+a1*lazy[v2][0][1]+lazy[v2][0][2])*lazy[v][0][0]+(a0*lazy[v2][1][0]+a1*lazy[v2][1][1]+lazy[v2][1][2])*lazy[v][0][1]+lazy[v][0][2],
       (a0*lazy[v2][0][0]+a1*lazy[v2][0][1]+lazy[v2][0][2])*lazy[v][1][0]+(a0*lazy[v2][1][0]+a1*lazy[v2][1][1]+lazy[v2][1][2])*lazy[v][1][1]+lazy[v][1][2])
**/


      temp[0][0]=lazy[v2][0][0]*lazy[v][0][0]+lazy[v2][1][0]*lazy[v][0][1];
      temp[0][1]=lazy[v2][0][1]*lazy[v][0][0]+lazy[v2][1][1]*lazy[v][0][1];
      temp[0][2]=lazy[v2][0][2]*lazy[v][0][0]+lazy[v2][1][2]*lazy[v][0][1]+lazy[v][0][2];

      temp[1][0]=lazy[v2][0][0]*lazy[v][1][0]+lazy[v2][1][0]*lazy[v][1][1];
      temp[1][1]=lazy[v2][0][1]*lazy[v][1][0]+lazy[v2][1][1]*lazy[v][1][1];
      temp[1][2]=lazy[v2][0][2]*lazy[v][1][0]+lazy[v2][1][2]*lazy[v][1][1]+lazy[v][1][2];


      for (int i=0;i<=1;i++){
        for (int j=0;j<=2;j++){
          lazy[v2][i][j]=temp[i][j];
        }
      }


    }
    if(lazy[v][0][2]>1){
     // cout<<"add "<<v<<" : "<<tl<<" and "<<tr<<" : "<<lazy[v][0][2]<<" "<<lazy[v][1][2]<<"\n";
    }
  }
  reset_lazy(v);
}

ld tr[2][3];

void apply(int v,int tl,int tr_,int l,int r){
  //cout<<" = "<<tl<<" "<<tr_<<" out of "<<l<<" "<<r<<"\n";
  push(v,tl,tr_);
  if(tr_<l||r<tl) return;
  if(l<=tl&&tr_<=r){
    for(int i=0;i<=1;i++){
      for(int j=0;j<=2;j++){
        lazy[v][i][j]=tr[i][j];
      }
    }
    return;
  }
  int tm=(tl+tr_)/2;
  apply(2*v,tl,tm,l,r);
  apply(2*v+1,tm+1,tr_,l,r);
}

void rep(int v,int tl,int tr_,int i){
 // cout<<"\t\t\t\t"<<v<<" : "<<tl<<" "<<tr_<<"\n";
  push(v,tl,tr_);
  if(tr_<i||i<tl) return;
  if(tl==tr_){
    return;
  }
  int tm=(tl+tr_)/2;
  rep(2*v,tl,tm,i);
  rep(2*v+1,tm+1,tr_,i);
}

void rep(int i){
  rep(1,0,n-1,i);
}

void apply(int l,int r){
  if(l>r) return;

  assert(0<=l&&l<=r&&r<n);

  apply(1,0,n-1,l,r);
}

void __move(int id,ld len){
  id--;
  assert(0<=id&&id+1<n);

  tr[0][0]=tr[0][1]=tr[0][2]=tr[1][0]=tr[1][1]=tr[1][2]=0;

  rep(id+1);
  rep(id);

  tr[0][2]=value[id+1][0]-value[id][0];
  tr[1][2]=value[id+1][1]-value[id][1];


  ld norm=sqrt(sqr(tr[0][2])+sqr(tr[1][2]));

  tr[0][2]/=norm;
  tr[1][2]/=norm;

  tr[0][2]*=len;
  tr[1][2]*=len;

  tr[0][0]=1;
  tr[1][1]=1;

  apply(id+1,n-1);

}



void __rotate(int id,ld ang){
  ang=ang/180*pi;
  id--;
  assert(0<=id&&id+1<n);




  rep(id);

  {
    tr[0][0]=tr[0][1]=tr[0][2]=tr[1][0]=tr[1][1]=tr[1][2]=0;


    tr[0][2]=-value[id][0];
    tr[1][2]=-value[id][1];

    tr[0][0]=1;
    tr[1][1]=1;

    apply(id+1,n-1);
  }
  {
    tr[0][0]=tr[0][1]=tr[0][2]=tr[1][0]=tr[1][1]=tr[1][2]=0;

    ld cs=cos(ang);
    ld sn=sin(ang);
    tr[0][0]=cs;
    tr[0][1]=sn;

    tr[1][0]=-sn;
    tr[1][1]=cs;

    apply(id+1,n-1);


  }


  {
    tr[0][0]=tr[0][1]=tr[0][2]=tr[1][0]=tr[1][1]=tr[1][2]=0;

    tr[0][2]=+value[id][0];
    tr[1][2]=+value[id][1];

    tr[0][0]=1;
    tr[1][1]=1;

    apply(id+1,n-1);
  }
}


signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  for (int v=0;v<4*N;v++){
    lazy[v][0][0]=1;
    lazy[v][1][1]=1;
  }

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  cin>>n>>q;
  n++;
  for (int i=0;i<n;i++) {
    value[i][0]=i;
  }
  while (q--) {
    //cout<<"#################\n";
    int type;
    cin>>type;
    assert(type==1||type==2);
    if(type==1){
      int id,mvlen;
      cin>>id>>mvlen;
      __move(id,mvlen);
    }else{
      assert(type==2);
      int id,ang;
      cin>>id>>ang;
      __rotate(id,ang);
    }
   // print_all();
   // exit(0);

    rep(n-1);

   // cout<<fixed<<setprecision(6)<<a[n-1][0]<<" "<<a[n-1][1]<<" | "<<value[n-1][0]<<" "<<value[n-1][1]<<"\n";
    cout<<fixed<<setprecision(6)<<value[n-1][0]<<" "<<value[n-1][1]<<"\n";

  }
}