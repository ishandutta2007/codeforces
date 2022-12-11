#include<bits/stdc++.h>

using namespace std;

string a[2];

bool comp(int x1, int y1, int i1, int x2, int y2, int i2){
  for(int i = 0;i <= y1-x1;++i){
    if(a[i1][x1+i] != a[i2][x2+i]) return false;
  }
  return true;
}

bool f(int x1, int y1, int i1, int x2, int y2, int i2){
  if((y1-x1+1)%2 == 1) return comp(x1,y1,i1,x2,y2,i2);
  return ((f(x1,(x1+y1)/2,i1,x2,(x2+y2)/2,i2) and f(1+(x1+y1)/2,y1,i1,1+(x2+y2)/2,y2,i2)) or 
  (f(x1,(x1+y1)/2,i1,1+(x2+y2)/2,y2,i2) and f(x2,(x2+y2)/2,i2,1+(x1+y1)/2,y1,i1)));
}

int main(){
  cin>>a[0]>>a[1];
  if(f(0,a[0].size()-1,0,0,a[1].size()-1,1)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}