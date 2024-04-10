#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a(100010,0);
vector<int> c(100010,0);
int punto=-1;
bool casi=0;
int punto2;
int main(){
  //freopen("transform.in", "r", stdin);
  //freopen("transform.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  string b;
  cin>>b;
  if(N%2==0){
    if(b[N/2]!='0'){
      punto=N/2;
    }else{
      int sx=N/2-1;
      int dx=N/2+1;
      while(punto<0){
        if(b[sx]!='0' && b[dx]=='0')punto=sx;
        else if(b[sx]=='0' && b[dx]!='0')punto=dx;
        else if(b[sx]=='0' && b[dx]=='0'){sx--; dx++; continue;}
        else {
          casi=1;
          punto=sx;
          punto2=dx;
        }
      }
    }
  }else{
    int sx=N/2;
    int dx=N/2+1;
    while(punto<0){
      if(b[sx]!='0' && b[dx]=='0')punto=sx;
      else if(b[sx]=='0' && b[dx]!='0')punto=dx;
      else if(b[sx]=='0' && b[dx]=='0'){sx--; dx++; continue;}
      else {
        casi=1;
        punto=sx;
        punto2=dx;
      }
    }
  }
  for(int i=punto-1;i>=0;i--){
    a[punto-1-i]+=b[i]-'0';
  }
  for(int i=N-1;i>=punto;i--){
    a[N-1-i]+=b[i]-'0';
  }
  for(int i=0;i<a.size();i++){
    if(a[i]>=10){
      a[i]=a[i]%10;
      a[i+1]++;
    }
  }
  if(casi==0){
    bool zero=0;
    for(int i=a.size()-1;i>=0;i--){
      if(a[i]>0){
        zero=1;
      }
      if(zero)cout<<a[i];
    }
  }else{
    for(int i=punto2-1;i>=0;i--){
      c[punto2-1-i]+=b[i]-'0';
    }
    for(int i=N-1;i>=punto2;i--){
      c[N-1-i]+=b[i]-'0';
    }
    for(int i=0;i<c.size();i++){
      if(c[i]>=10){
        c[i]=c[i]%10;
        c[i+1]++;
      }
    }
    for(int i=a.size()-1;i>=0;i--){
      if(a[i]>0)break;
      else a.erase(a.begin()+i);
    }
    for(int i=c.size()-1;i>=0;i--){
      if(c[i]>0)break;
      else c.erase(c.begin()+i);
    }
    reverse(a.begin(),a.end());
    reverse(c.begin(),c.end());
    char giusto='a';
    if(a.size()<c.size())giusto='a';
    else if(c.size()<a.size())giusto='c';
    else {
      for(int i=0;i<a.size();i++){
        if(a[i]<c[i]){giusto='a';break;}
        if(c[i]<a[i]){
          giusto='c';
          break;
        }
      }
    }
    if(giusto=='a')for(int i=0;i<a.size();i++)cout<<a[i];
    else for(int i=0;i<c.size();i++)cout<<c[i];
  }
  return 0;
}