//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << max({a + b + c,(a + b) * c,a * (b + c),a * b * c,a + b * c,a * b + c});
}