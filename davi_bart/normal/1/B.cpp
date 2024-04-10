#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int string_to_n(string p){
  int k=0;
  for(int i=0;i<p.size();i++){
    k*=26;
    k+=p[i]-'A'+1;
  }
  return k;
}
string to_st(int h){
  string k;
  while(h>0){
    h--;
    k+='A'+h%26;
    h/=26;
  }
  reverse(k.begin(),k.end());
  return k;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    while(N--){
      string a;
      cin>>a;
      bool k=0;
      for(int i=1;i<a.size();i++){
          if(0<=(a[i]-'A') && (a[i]-'A')<26 && 0<=(a[i-1]-'0') && (a[i-1]-'0')<10){
            k=1;
            break;
          }
      }
      if(k==0){
        int pos=0;
        while(0<=(a[pos]-'A') && (a[pos]-'A')<26)pos++;
        string j=a.substr(0,pos);
        int h=0;
        while(pos<a.size()){
          h*=10;
          h+=a[pos]-'0';
          pos++;
        }
        cout<<'R'<<h<<'C'<<string_to_n(j)<<'\n';
        continue;
      }
      int pos=1;
      int c=0,d=0;
      while(a[pos]!='C'){
        c*=10;
        c+=a[pos]-'0';
        pos++;
      }
      pos++;
      while(pos<a.size()){
        d*=10;
        d+=a[pos]-'0';
        pos++;
      }
      cout<<to_st(d)<<c<<'\n';
    }
    return 0;
}