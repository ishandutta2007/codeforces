#include <bits/stdc++.h>

using namespace std;

const int N=5000+7;
int n,q;

void add(int aib[N][N], int d1, int d2, int r, int c, int x) {
  for(int i=r;i<=d1;i+=i&(-i))for(int j=c;j<=d2;j+=j&(-j))aib[i][j]+=x;
}

int get(int aib[N][N], int d1, int d2, int r, int c) {
  int sol=0;
  for(int i=r;i>=1;i-=i&(-i))for(int j=c;j>=1;j-=j&(-j))sol+=aib[i][j];
  return sol;
}

int aib1[N][N];
int aib2[2*N][N];
int aib3[2*N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n>>q;
  for (int iq=1;iq<=q;iq++) {
    int type;
    cin>>type;
    if(type==1){
      int dir,x,y,l;
      cin>>dir>>x>>y>>l;
      if(dir==1) {
        add(aib1,n,n,x,y,+1);
        add(aib1,n,n,x,y+l+1,-1);
        add(aib2,2*n,n,x+y+l+1,y,-1);
        add(aib2,2*n,n,x+y+l+1,y+l+1,+1);
      }
      if(dir==2){
        add(aib1,n,n,x,y-l,+1);
        add(aib1,n,n,x,y+1,-1);
        add(aib3,2*n,n,x-y+l+n+1,y-l,-1);
        add(aib3,2*n,n,x-y+l+n+1,y+1,+1);
      }
      if(dir==3){
        add(aib1,n,n,x+1,y,-1);
        add(aib1,n,n,x+1,y+l+1,+1);
        add(aib3,2*n,n,x-y-l+n,y,+1);
        add(aib3,2*n,n,x-y-l+n,y+l+1,-1);
      }
      if(dir==4){
        add(aib1,n,n,x+1,y-l,-1);
        add(aib1,n,n,x+1,y+1,+1);
        add(aib2,2*n,n,x+y-l,y-l,+1);
        add(aib2,2*n,n,x+y-l,y+1,-1);
      }
    }else{
      int a,b;
      cin>>a>>b;
      cout<<get(aib1,n,n,a,b)+get(aib2,2*n,n,a+b,b)+get(aib3,2*n,n,a-b+n,b)<<"\n";
    }
  }
}