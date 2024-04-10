//***In the name of GOD***\\

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
// for(int i = 0;i < n; i++)

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n; i++){
      cin >> a[i];
      if(a[i] > 2048){
        a[i] = 0;
      }
    }
    sort(a, a + n);
    for(int i = 0;i < n / 2; i++){
      swap(a[i] , a[(n - i) - 1]);
    }
    int c = 0 , sum = 0;
    for(int i = 0;i < n; i++){
      sum += a[i];
      if(sum == 2048){
        c++;
      }
    }
    if(c){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}