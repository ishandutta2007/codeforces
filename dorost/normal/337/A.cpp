#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define sz(s) s.size()

int main(){
  int n,m;
  cin >> n >> m;
  int a[m];
  for(int i = 0; i < m; i++){
    cin >> a[i];
  }
  sort(a, a + m);
  int mini = a[n - 1] - a[0];
  for(int i = 1,j = n ; j < m;j++){
    if(mini > (a[j] - a[i])){
      mini = (a[j] - a[i]);
    }
    i++;
  }
  cout << mini;
}