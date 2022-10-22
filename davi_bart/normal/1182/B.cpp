#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool a[505][505];
struct punto{
  int x,y;
};
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int h,w;
  cin>>h>>w;
  for(int i=0;i<h;i++){
    string g;
    cin>>g;
    for(int j=0;j<w;j++){
      if(g[j]=='.')a[i][j]=0;
      else a[i][j]=1;
    }
  }
  punto centro;
  bool p=0;
  for(int i=1;i<h-1;i++){
    for(int j=1;j<w-1;j++){
      if(a[i][j] && a[i][j+1] && a[i][j-1] && a[i+1][j] && a[i-1][j]){
        centro.y=i;
        centro.x=j;
        p=1;
        break;
      }
    }
    if(p)break;
  }
  if(p==0){
    cout<<"NO";
    return 0;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] && i!=centro.y && j!=centro.x){
        cout<<"NO";
        return 0;
      }
    }
  }
  bool k=1;
  for(int i=centro.x;i<w;i++){
    if(a[centro.y][i]){
      if(k)continue;
      else {
        cout<<"NO";
        return 0;
      }
    }else k=0;
  }
  k=1;
  for(int i=centro.x;i>=0;i--){
    if(a[centro.y][i]){
      if(k)continue;
      else {
        cout<<"NO";
        return 0;
      }
    }else k=0;
  }
  k=1;
  for(int i=centro.y;i>=0;i--){
    if(a[i][centro.x]){
      if(k)continue;
      else {
        cout<<"NO";
        return 0;
      }
    }else k=0;
  }
  k=1;
  for(int i=centro.y;i<h;i++){
    if(a[i][centro.x]){
      if(k)continue;
      else {
        cout<<"NO";
        return 0;
      }
    }else k=0;
  }
  cout<<"YES";
  return 0;
}