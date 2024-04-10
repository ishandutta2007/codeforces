//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++){
    cout << a[i] << ' ';
  }
}