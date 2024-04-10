#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,maxa=0,maxb=0;
  cin>>n;
  int a[n],b[m];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i == 0){
      maxa=a[i];
    }else if(a[i] > maxa){
      maxa=a[i];
    }
  }
  cin >> m;
  for(int j = 0; j < m; j++){
    cin >> b[j];
    if(j == 0){
      maxb=b[j];
    }else if(b[j] > maxb){
      maxb=b[j];
    }
  }
  cout << maxa << ' ' << maxb;
}