//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define set(n) cout << fixed << setprecision(n);

int main(){
  int maxi = 0;
  fast;
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);
  if(a[1] - a[0] > a[n - 1] - a[n - 2]){
    cout << a[n - 1] - a[1];
  }else{
    cout << a[n - 2] - a[0];
  }
}