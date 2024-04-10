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
  int a[n],maxi = 0,sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    if(a[i] > maxi){
      maxi = a[i];
    }
  }
  cout << (maxi * n) - sum; 
}