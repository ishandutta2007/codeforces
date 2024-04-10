#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,zf=0,ef=0,rf=0,of=0,nf=0,q=0;
  int zg=0,eg=0,rg=0,og=0,ng=0;
  cin >> a;
  string s;
  cin >> s;
  for(int i = 0; i < a; i++){
    if(s[i] == 'z'){
      zf++;
      zg++;
    }
    if(s[i] == 'e'){
      ef++;
      eg++;
    }
    if(s[i] == 'r'){
      rf++;
      rg++;
    }
    if(s[i] == 'o'){
      of++;
      og++;
    }
    if(s[i] == 'n'){
      nf++;
      ng++;
    }
  }
  for(int j = 0; j < a / 3; j++){
    if(of && nf && ef){
      q++;
      of--;
      nf--;
      ef--;
    }else if(zf && ef && rf && of){
      q++;
      zf--;
      ef--;
      rf--;
      of--;
    }
  }
  int b[q],h=0;
  for(int j = 0; j < q; j++){
    if(og && ng && eg){
      b[j]=1;
      og--;
      ng--;
      eg--;
    }else if(zg && eg && rg && og){
      b[j]=0;
      zg--;
      eg--;
      rg--;
      og--;
    }
  }
  sort(b ,b + q);
  for(int c = q; c > 0; c--){
    cout << b[c-1] << ' ';
  }
}