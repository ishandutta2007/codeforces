//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << fixed << setprecision(6);
int main(){
  int n;
  cin >> n;
  int a[5]={10,11,12,13,14};
  for(int i = n + 1;true;i++){
    bool f = true;
    int h = i;
    for(int j = 0; j < 5; j++){
      a[j] = h % 10;
      h /= 10;
      if(h == 0){
        break;
      }
    }
    for(int j = 0; j < 5;j++){
      for(int k = 0; k < j; k++){
        if(a[j] == a[k]){
           f = false;
        }
      }
    }
    if(f){
      cout << i;
      return 0;
    }
  }
}